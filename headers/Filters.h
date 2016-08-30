#ifndef FILTERS_H
#define FILTERS_H

#include "opencv2/opencv.hpp"
#include "headers/Point.h"

namespace dynengines {
    class Filters {

    public :
        Filters();
        int invert();
        int extrude();

        cv::Mat setThreshold(cv::Mat imgIn);
        cv::Mat findEdges(cv::Mat imgIn);
        cv::Mat convert2Gray(cv::Mat imgIn);

    };
}

#endif // FILTERS_H
