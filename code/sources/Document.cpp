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

            for(int i=0;i<letterbox.size();++i)
                cv::rectangle(img, letterbox[i],cv::Scalar(0, 255, 0), 3, 8, 0);

            cv::imwrite("imgoutput.jpg", img);
        }

    }
}
