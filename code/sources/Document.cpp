#include <opencv2/opencv.hpp>
#include "headers/Document.h"
#include "headers/Blocks.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

namespace dynengines {
    namespace detector {

        const int alpha_slider_max = 100;
        int alpha_slider;
        double alpha;
        double beta;

        /// Matrices to store images
        Mat src1;
        Mat src2;
        Mat dst;

        Document::Document() {

        }

        void on_trackbar( int, void* )
        {
         alpha = (double) alpha_slider/alpha_slider_max ;
         beta = ( 1.0 - alpha );

         addWeighted( src1, alpha, src2, beta, 0.0, dst);

         //imshow( "Linear Blend", dst );

         while (true) {
            // cap >> image;

             imshow("window", dst);

             // delay 33ms
             waitKey(33);
         }
        }


        Mat Document::setTextBlocks(Mat imgIn) {
            Blocks blocks;

            vector<Rect> letterbox = blocks.detect(imgIn);

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
