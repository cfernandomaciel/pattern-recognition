#include "headers/Filters.h"

namespace dynengines {
    Filters::Filters() {

    }

    int Filters::invert() {

    }

    int Filters::extrude() {

    }


    cv::Mat Filters::findEdges(cv::Mat imgIn) {
        cv::Mat img_sobel;

        cv::Sobel(imgIn, img_sobel, CV_8U, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT);

        return img_sobel;
    }

    cv::Mat Filters::convert2Gray(cv::Mat imgIn) {
        cv::Mat img_gray;

        cvtColor(imgIn, img_gray, CV_BGR2GRAY);


        return img_gray;
    }

    cv::Mat Filters::setThreshold(cv::Mat imgIn) {
        cv::Mat img_threshold;

        cv::threshold(imgIn, img_threshold, 0, 255, CV_THRESH_OTSU+CV_THRESH_BINARY);

        return img_threshold;
    }
}
