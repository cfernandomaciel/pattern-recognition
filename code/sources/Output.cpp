#include <opencv2/opencv.hpp>
#include "headers/Document.h"
#include "headers/Blocks.h"
#include "headers/Output.h"
#include "headers/Output.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace dynengines::detector;
using namespace std;

namespace dynengines {

    Output::Output() {

    }


    void Output::renderVideo() {

        Document document;

        Mat img;
        VideoCapture cap;
        int camOpen = cap.open(CV_CAP_ANY);

        cv::namedWindow("Display Image", 1);

        while(true) {

            cap >> img;


            Mat imgOut = document.setTextBlocks(img);
            //alpha_slider = 0;

            //char TrackbarName[50];
            //sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );



           // createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );

           // on_trackbar( alpha_slider, 0 );


            if (!imgOut.empty()) {
                imshow("Display Image", imgOut);
            }

            waitKey(0);
        }

    }

    void Output::renderImage() {

        Document document;
        /*
        Mat image;



        alpha_slider = 0;
        char TrackbarName[50];
        sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );

        namedWindow("window", CV_WINDOW_AUTOSIZE);
        createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );

        on_trackbar( alpha_slider, 0 );
        */


        namedWindow("Display Image", 1);

        Mat imgIn  = imread("defaulttestimage.jpg");
        Mat imgOut = document.setTextBlocks(imgIn);

        if (!imgOut.empty()) {
            imshow("Display Image", imgOut);
        }

        waitKey(0);

        //cv::imwrite("imgoutput.jpg", imgOut);

        //alpha_slider = 0;

        //char TrackbarName[50];
        //sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );



       // createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );

       // on_trackbar( alpha_slider, 0 );




    }


    void Output::transformImage() {

        Document document;

        Mat imgIn = cv::imread("defaulttestimage.jpg");

        Mat imgOut = document.setTextBlocks(imgIn);

        cv::imwrite("imgoutput.jpg", imgOut);

    }
}
