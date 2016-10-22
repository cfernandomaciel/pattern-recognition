#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "opencv2/opencv.hpp"
#include <QString>

using namespace std;
namespace dynengines {
    namespace detector {

        class Document {
        public :
            Document(string name);
            cv::Mat setTextBlocks(cv::Mat imgIn);
            cv::Mat setTextBlocks(cv::Mat imgIn, int size);
            cv::Mat setTextBlocks(cv::Mat imgIn, int width, int height);

        private :
            int i;
            string document_name;
            cv::Mat drawRectangle(cv::Mat imgIn, std::vector<cv::Rect> letterbox);
            void cut(cv::Mat imgIn, cv::Rect rect);
            void createFolder();

        };


    }
}

#endif // DOCUMENT_H
