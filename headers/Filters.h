#ifndef FILTERS_H
#define FILTERS_H

namespace dynengines {
    class Filters {
    public :
        Filters::Filters();
        int invert();
        int extrude();
        int crop(cv::Mat imgIn, Point coordinates);
        cv::Mat deviate(cv::Mat imgIn);
        cv::Mat convert2Gray(cv::Mat imgIn);

    };
}

#endif // FILTERS_H
