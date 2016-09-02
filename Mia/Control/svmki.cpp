#include "svmki.h"

#include <ctime>
#include <cstdlib>

SVMKI::SVMKI()
{
    mcallNr = 2;
    std::srand(std::time(NULL));

    /*
     * Nr = 1: Wenn zur lüge gezwungen: Nächst größere
     * Nr = 2: Wenn zur lüge gezwungen: Zufällig
     * Nr = 3: Gibt immer einen zufälligen Wert
     * Nr = 4: Lügt immer, egal ob groß oder klein
     */

    mValue[0] = 31;
    mValue[1] = 31;
    mValue[2] =32;
    mValue[3] =32;
    mValue[4] =41;
    mValue[5] =41;
    mValue[6] =42;
    mValue[7] =42;
    mValue[8] =43;
    mValue[9] =43;
    mValue[10] =51;
    mValue[11] =51;
    mValue[12] =52;
    mValue[13] =52;
    mValue[14] =53;
    mValue[15] =53;
    mValue[16] =54;
    mValue[17] =54;
    mValue[18] =61;
    mValue[19] =61;
    mValue[20] =62;
    mValue[21] =62;
    mValue[22] =63;
    mValue[23] =63;
    mValue[24] =64;
    mValue[25] =64;
    mValue[26] =65;
    mValue[27] =65;
    mValue[28] =11;
    mValue[29] =22;
    mValue[30] =33;
    mValue[31] =44;
    mValue[32] =55;
    mValue[33] =66;
    mValue[34] =21;
    mValue[35] =21;

    /*
    float labels[2] = {255, 0};
    lierlabel = cv::Mat(2, 1, CV_32FC1, labels);
    float trainingData[2][3] = { {1, 54, 31}, {0, 33, 63} };
    dataInput = cv::Mat(2, 3, CV_32FC1, trainingData);
    */

    /*
    CvMLData mlData;
    mlData.read_csv("learn_data.csv");
    const CvMat* tmp = mlData.get_values();
    cv::Mat allData(tmp,true);
    tmp->CvMat::~CvMat();

    cv::Mat lierlabel;
    cv::compare(allData.col(4),allData.col(5),lierlabel,cv::CMP_EQ);
    lierlabel.convertTo(lierlabel,CV_32FC1);

    std::vector<cv::Mat> in;
    in.push_back(allData.col(3));
    in.push_back(allData.col(4));
    in.push_back(allData.col(6));
    cv::Mat dataInput;
    cv::hconcat(in,dataInput);
    dataInput.convertTo(dataInput,CV_32FC1);
*/
}

SVMKI::~SVMKI()
{

}

bool SVMKI::look_at_dice(Value last, Value call, bool startGame){

    CvSVMParams params;
    params.svm_type = CvSVM::C_SVC;
    params.kernel_type = CvSVM::RBF;//LINEAR - RBF

    CvSVM SVM;
    SVM.train(dataInput, lierlabel, cv::Mat(), cv::Mat(), params);

    cv::Mat sampleMat = (cv::Mat_<float>(1,3) << (int)startGame,call.toInt(),last.toInt());
    float response = SVM.predict(sampleMat);
    return response == 0;
}

int SVMKI::getStartCall(Value v){
    return v.toInt();
}

// Feste Rückgabe - Wahrheit oder den nächst größere Wert
int SVMKI::getCall_next(Value last, Value rand){
    if(rand.greater_than(last)){
        return rand.toInt();
    }else{
        if(last.pasch){
            if(last.toInt() == 66){
                return 21;
            }else{
                return last.toInt()+11;
            }
        }else if(last.mia){
            return 21;
        }else if(last.toInt() == 65){
            return 11;
        }else{
            if(last.lowval+1 < last.highval){
                return last.toInt()+1;
            }else{
                return (last.highval+1)*10+1;
            }
        }
    }
}
int SVMKI::getCall_rand(Value last, Value get){

    if(get.greater_than(last)){
        return get.toInt();
    }else{
        for(int i = 0; i < 36; i++){
            if(mValue[i] == last.toInt()){
                return mValue[1+i+(rand() %(35-i))];
            }
        }
        return mValue[rand() %36];
    }
}
int SVMKI::getCall_always(Value last, Value get){
    for(int i = 0; i < 36; i++){
        if(mValue[i] == last.toInt()){
            return mValue[1+i+(rand() %(35-i))];
        }
    }
    return mValue[rand() %36];
}
int SVMKI::getCall_never(Value last, Value get){
    int ret = 35;
    if(!get.greater_than(last)){
        for(int i = 0; i < 36; i++){
            if(mValue[i] == last.toInt()){
                ret = 1+i+(rand() %(35-i));
                break;
            }
        }
    }else{
        int l,g;
        for(int i = 0; i < 36; i++){
            if(mValue[i] == last.toInt()){
                l=i;
            }
            if(mValue[i] == get.toInt()){
                g=i;
                break;
            }
        }
        ret = l+(rand()%(g-l));
    }
    return mValue[ret];
}

int SVMKI::getCall(Value last, Value get){
    if(last.toInt()> 66 || get.toInt() > 66){
        std::cout<<"Zu Groß: "<<last.toInt()<<" "<<get.toInt()<<std::endl;
    }
    if(mcallNr == 1){
        return getCall_next(last,get);
    }else if(mcallNr == 2){
        return getCall_rand(last,get);
    }else if(mcallNr == 3){
        return getCall_always(last,get);
    }else if(mcallNr == 4){
        return getCall_never(last,get);
    }else{
        return getCall_next(last,get);
    }
}

void SVMKI::learn(Value call, Value rand, Value last, bool startGame){
    float lab = 0;
    if(call.equal(rand)||call.less_than(rand)){
        lab = 255;
    }
    cv::Mat tmpl(1, 1, CV_32FC1, lab);
    lierlabel.push_back(tmpl);
    float tmp[3] = {startGame,call.toInt(),last.toInt()};
    cv::Mat tmp2(1,3,CV_32FC1,tmp);
    dataInput.push_back(tmp2);
}

void SVMKI::save(){
    CvSVMParams params;
    params.svm_type = CvSVM::C_SVC;
    params.kernel_type = CvSVM::RBF;//LINEAR - RBF

    CvSVM SVM;
    SVM.train(dataInput, lierlabel, cv::Mat(), cv::Mat(), params);
    //    Dies kann zur visualisierung verwendet werden
    cv::Mat image = cv::Mat::zeros(77,154,CV_8UC3);
    cv::Vec3b green(0,255,0), blue (255,0,0);
    // Show the decision regions given by the SVM
    for (int i = 0; i < image.rows; ++i)
        for (int j = 0; j < image.cols; ++j)
        {
            int s = 0;
            int t = j;
            if(j > 77){
                s = 1;
                t = j -77;
            }
            cv::Mat sampleMat = (cv::Mat_<float>(1,3) << s,t,i);
            float response = SVM.predict(sampleMat);

            if (response == 255)
                image.at<cv::Vec3b>(i,j)  = green;
            else if (response == 0)
                image.at<cv::Vec3b>(i,j)  = blue;
        }
    imwrite("result.png", image);        // save the image

    imshow("SVM Simple Example", image); // show it to the user

    cv::waitKey(0);
}
