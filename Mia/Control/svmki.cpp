#include "svmki.h"

SVMKI::SVMKI()
{
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

    /*
//    Dies kann zur visualisierung verwendet werden
    cv::Mat image = cv::Mat::zeros(100,200,CV_8UC3);
    cv::Vec3b green(0,255,0), blue (255,0,0);
    // Show the decision regions given by the SVM
    for (int i = 0; i < image.rows; ++i)
        for (int j = 0; j < image.cols; ++j)
        {
            int s = 0;
            int t = j;
            if(j > 100){
                s = 1;
                t = j -100;
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
int SVMKI::getCall(Value last, Value rand){
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

void SVMKI::learn(Value call, Value rand, Value last, bool startGame){
    float lab = 0;
    if(call.equal(rand)){
        lab = 255;
    }
    cv::Mat tmpl(1, 1, CV_32FC1, lab);
    lierlabel.push_back(tmpl);
    float tmp[3] = {startGame,call.toInt(),last.toInt()};
    cv::Mat tmp2(1,3,CV_32FC1,tmp);
    dataInput.push_back(tmp2);
}
