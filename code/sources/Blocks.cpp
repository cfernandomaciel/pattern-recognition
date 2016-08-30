#include "opencv2/opencv.hpp"
#include "headers/Blocks.h"
#include "headers/Filters.h"

namespace dynengines {
    namespace detector {

        Blocks::Blocks() {

        }

        std::vector<cv::Rect> Blocks::detect(cv::Mat img) {

            Filters filters;

            std::vector<cv::Rect> boundRect;
            cv::Mat img_gray, img_sobel, img_threshold, element;



            img_gray = filters.convert2Gray(img);
            img_sobel = filters.findEdges(img_gray);
            img_threshold = filters.setThreshold(img_sobel);


            element = getStructuringElement(cv::MORPH_RECT, cv::Size(25, 10) );
            //element = getStructuringElement(cv::MORPH_RECT, cv::Size(17, 3) );
            //element = getStructuringElement(cv::MORPH_RECT, cv::Size(30, 30) );
            //element = getStructuringElement(cv::MORPH_RECT, cv::Size(45, 45) );

            cv::morphologyEx(img_threshold, img_threshold, CV_MOP_CLOSE, element); //Does the trick

            std::vector< std::vector< cv::Point> > contours;

            cv::findContours(img_threshold, contours, 0, 1);

            std::vector<std::vector<cv::Point> > contours_poly( contours.size() );

            for( int i = 0; i < contours.size(); i++ )
                if (contours[i].size()>100)
                {
                    cv::approxPolyDP( cv::Mat(contours[i]), contours_poly[i], 3, true );
                    cv::Rect appRect( boundingRect( cv::Mat(contours_poly[i]) ));
                    if (appRect.width>appRect.height)
                        boundRect.push_back(appRect);
                }


            return boundRect;
        }

    }
}
