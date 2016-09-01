#include "opencv2/opencv.hpp"
#include "headers/Blocks.h"
#include "headers/Filters.h"

namespace dynengines {
    namespace detector {

        Blocks::Blocks() {

        }

        std::vector<cv::Rect> Blocks::detect(cv::Mat img, int width, int height) {

            Filters filters;

            std::vector<cv::Rect> boundRect;
            cv::Mat img_gray, img_sobel, img_threshold, element;



            img_gray = filters.convert2Gray(img);
            img_sobel = filters.findEdges(img_gray);
            img_threshold = filters.setThreshold(img_sobel);

            if( width <= 0 )
                width = 1;

            if( height <= 0)
                height = 1;


            element = getStructuringElement(cv::MORPH_RECT, cv::Size(width, height) );

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
