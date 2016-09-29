#include <opencv2/opencv.hpp>
#include "headers/Document.h"
#include "headers/Blocks.h"
#include "headers/Output.h"
#include "headers/Output.h"
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace dynengines::detector;
using namespace std;

namespace dynengines {


    Mat imgIn;
    VideoCapture cap;
    int iBrightness;
    double dContrast;

    int iSliderValue1;
    int iSliderValue2;
    int iSliderWidth;
    int iSliderHeight;

    Document document;

    Output::Output() {

    }

    void Output::renderVideo() {        

        Mat img;        
        int camOpen = cap.open(CV_CAP_ANY);

        namedWindow("Video", CV_WINDOW_NORMAL);

        iSliderValue1 = 50;
        createTrackbar("Brightness", "Video", &iSliderValue1, 100);


        iSliderValue2 = 50;
        createTrackbar("Contrast", "Video", &iSliderValue2, 100);

        iSliderWidth = 25;
        createTrackbar("Width", "Video", &iSliderWidth, 100);

        iSliderHeight = 10;
        createTrackbar("Height", "Video", &iSliderHeight, 100);

        while(true) {

            cap >> img;

            Mat dst;
            iBrightness  = iSliderValue1 - 50;
            dContrast = iSliderValue2 / 50.0;

            img.convertTo(dst, -1, dContrast, iBrightness);


            Mat imgOut = document.setTextBlocks(dst, iSliderWidth, iSliderHeight);

            cvSetTrackbarPos("Brightness","Video",iSliderValue1);
            cvSetTrackbarPos("Contrast","Video",iSliderValue2);

            cvSetTrackbarPos("Width","Video",iSliderWidth);
            cvSetTrackbarPos("Height","Video",iSliderHeight);


            if (!imgOut.empty()) {
                imshow("Video", imgOut);
            }

            //waitKey(0);
            int iKey = waitKey(50);

            if (iKey == 27) {
                  break;
            }
        }

    }

    void on_trackbar_brightness( int, void* ) {
        Mat dst;
        iBrightness  = iSliderValue1 - 50;
        dContrast = iSliderValue2 / 50.0;

        imgIn.convertTo(dst, -1, dContrast, iBrightness);


        Mat imgBlocks = document.setTextBlocks(dst, iSliderWidth, iSliderHeight);

        cvSetTrackbarPos("Brightness","Video",iSliderValue1);

        Mat imgOut = document.setTextBlocks(imgBlocks);

        if (!imgOut.empty()) {
            imshow("Video", imgOut);
        }
    }

    void on_trackbar_contrast( int, void* ) {
        Mat dst;
        iBrightness  = iSliderValue1 - 50;
        dContrast = iSliderValue2 / 50.0;

        imgIn.convertTo(dst, -1, dContrast, iBrightness);


        Mat imgBlocks = document.setTextBlocks(dst, iSliderWidth, iSliderHeight);

        cvSetTrackbarPos("Contrast","Video",iSliderValue2);

        Mat imgOut = document.setTextBlocks(imgBlocks);

        if (!imgOut.empty()) {
            imshow("Picture", imgOut);
        }
    }

    void on_trackbar_height( int, void* ) {
        Mat dst;
        iBrightness  = iSliderValue1 - 50;
        dContrast = iSliderValue2 / 50.0;

        imgIn.convertTo(dst, -1, dContrast, iBrightness);


        Mat imgBlocks = document.setTextBlocks(dst, iSliderWidth, iSliderHeight);

        cvSetTrackbarPos("Height","Video",iSliderHeight);

        Mat imgOut = document.setTextBlocks(imgBlocks);

        if (!imgOut.empty()) {
            imshow("Picture", imgOut);
        }
    }

    void on_trackbar_width( int, void* ) {
        Mat dst;
        iBrightness  = iSliderValue1 - 50;
        dContrast = iSliderValue2 / 50.0;

        imgIn.convertTo(dst, -1, dContrast, iBrightness);


        Mat imgBlocks = document.setTextBlocks(dst, iSliderWidth, iSliderHeight);

        cvSetTrackbarPos("Width","Video",iSliderWidth);


        Mat imgOut = document.setTextBlocks(imgBlocks);

        if (!imgOut.empty()) {
            imshow("Picture", imgOut);
        }
    }

    void Output::renderImage() {        

        namedWindow("Video", CV_WINDOW_NORMAL);

        iSliderValue1 = 50;
        createTrackbar("Brightness", "Video", &iSliderValue1, 100, on_trackbar_brightness);


        iSliderValue2 = 50;
        createTrackbar("Contrast", "Video", &iSliderValue2, 100, on_trackbar_contrast);

        iSliderWidth = 25;
        createTrackbar("Width", "Video", &iSliderWidth, 100, on_trackbar_width);

        iSliderHeight = 10;
        createTrackbar("Height", "Video", &iSliderHeight, 100, on_trackbar_height);


        imgIn  = imread("defaulttestimage.jpg");

        on_trackbar_brightness( 0, 0 );       

        waitKey(0);

    }


    void Output::transformImage(std::string src, std::string dst) {

        Document document;

        Mat imgIn = cv::imread("defaulttestimage.jpg");

        Mat imgOut = document.setTextBlocks(imgIn);

        cv::imwrite("imgoutput.jpg", imgOut);

    }
}
