#ifndef SVMKI_H
#define SVMKI_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>
#include <iostream>

#include "Model/value.h"
#include "ki.h"

class SVMKI : public KI
{
private:
    float labels[2] = {255, 0};
    cv::Mat lierlabel = cv::Mat(2, 1, CV_32FC1, labels);
    float trainingData[2][3] = { {1, 54, 31}, {0, 33, 63} };
    cv::Mat dataInput = cv::Mat(2, 3, CV_32FC1, trainingData);

public:
    SVMKI();
    ~SVMKI();
    bool look_at_dice(Value last, Value call, bool startGame);
    int getCall(Value last, Value rand);
    int getStartCall(Value v);
    void learn(Value call, Value rand, Value last, bool startGame);
};

#endif // SVMKI_H
