#include <opencv2/opencv.hpp>
#include "headers/Document.h"
#include "headers/Blocks.h"


namespace dynengines {
    namespace detector {

        Document::Document() {

        }

        void Document::setTexBlocks() {
            Blocks blocks;

            cv::Mat img = cv::imread("defaulttestimage.jpg");
            std::vector<cv::Rect> letterbox = blocks.detect(img);

            cv::Mat imgOut = drawRectangle(img, letterbox);

            cv::imwrite("imgoutput.jpg", imgOut);
        }

        cv::Mat Document::drawRectangle(cv::Mat imgIn, std::vector<cv::Rect> letterbox) {
            for(int i=0;i<letterbox.size();++i)
                cv::rectangle(imgIn, letterbox[i],cv::Scalar(0, 255, 0), 3, 8, 0);


            return imgIn;
        }



    }
}
