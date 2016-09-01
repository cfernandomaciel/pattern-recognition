#include <opencv2/opencv.hpp>
#include "headers/Document.h"
#include "headers/Blocks.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

namespace dynengines {
    namespace detector {        

        Document::Document() {

        }


        Mat Document::setTextBlocks(Mat imgIn) {
            Blocks blocks;

            vector<Rect> letterbox = blocks.detect(imgIn, 25, 10);

            Mat imgOut = drawRectangle(imgIn, letterbox);


            return imgOut;
        }

        Mat Document::setTextBlocks(Mat imgIn, int size) {
            Blocks blocks;

            vector<Rect> letterbox = blocks.detect(imgIn, size, size);

            Mat imgOut = drawRectangle(imgIn, letterbox);


            return imgOut;
        }

        Mat Document::setTextBlocks(Mat imgIn, int width, int height) {
            Blocks blocks;

            vector<Rect> letterbox = blocks.detect(imgIn, width, height);

            Mat imgOut = drawRectangle(imgIn, letterbox);


            return imgOut;
        }

        cv::Mat Document::drawRectangle(cv::Mat imgIn, std::vector<cv::Rect> letterbox) {
            for(int i=0;i<letterbox.size();++i)
                cv::rectangle(imgIn, letterbox[i],cv::Scalar(0, 255, 0), 3, 8, 0);


            return imgIn;
        }



    }
}
