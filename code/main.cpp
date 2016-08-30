#include <iostream>
#include <opencv2/opencv.hpp>
#include "headers/Blocks.h"

using namespace std;
using namespace cv;
using namespace dynengines::detector;

int main(int, char **)
{
    Blocks blocks;

    cv::Mat img3 = cv::imread("business card 2.jpg");
    std::vector<cv::Rect> letterBBoxes3 = blocks.detect(img3);

    for(int i=0;i<letterBBoxes3.size();++i)
        cv::rectangle(img3, letterBBoxes3[i],cv::Scalar(0, 255, 0), 3, 8, 0);

    cv::imwrite("imgOut3.jpg", img3);

    return 0;
}

