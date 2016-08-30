#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "opencv2/opencv.hpp"

namespace dynengines {
    namespace detector {

        class Document {
        public :
            Document();
            void setTexBlocks();

        private :
            cv::Mat drawRectangle(cv::Mat imgIn, std::vector<cv::Rect> letterbox);

        };


    }
}

#endif // DOCUMENT_H
