#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "opencv2/opencv.hpp"

namespace dynengines {
    namespace detector {

        class Document {
        public :
            Document();
            cv::Mat setTextBlocks(cv::Mat imgIn);
            cv::Mat setTextBlocks(cv::Mat imgIn, int size);
            cv::Mat setTextBlocks(cv::Mat imgIn, int width, int height);

        private :
            cv::Mat drawRectangle(cv::Mat imgIn, std::vector<cv::Rect> letterbox);
            void cut(cv::Mat imgIn, cv::Rect rect);

        };


    }
}

#endif // DOCUMENT_H
