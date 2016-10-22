#include <opencv2/opencv.hpp>
#include "headers/Document.h"
#include "headers/Blocks.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <QString>
#include <QDir>


using namespace cv;
using namespace std;

namespace dynengines {
    namespace detector {        

        Document::Document(string name) {
            i = 0;
            document_name = name;
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
            if(letterbox.size() > 0) {
                cout << "\"boxes\" : [ ";
            }
            for(int i=0;i<letterbox.size();++i) {
                cout << "{ \"width\":  " << letterbox[i].width << ", \"height\": " << letterbox[i].height;
                cout << ", \"x\": " << letterbox[i].x << ", \"y\": " << letterbox[i].y;

                if((i+1) != letterbox.size()) {
                    cout << "},";
                } else {
                    cout << "}";
                }
                cut(imgIn, letterbox[i]);
                cv::rectangle(imgIn, letterbox[i],cv::Scalar(0, 255, 0), 3, 8, 0);
            }
            if(letterbox.size() > 0) {
                cout << "]\n";
            }

            return imgIn;
        }

        void Document::cut(cv::Mat imgIn, cv::Rect rect) {
            cv::Mat crop = imgIn(rect);

            stringstream ss;
            ss << i;

            string str = ss.str();

            createFolder();
            QString path = QString::fromLocal8Bit(document_name.c_str()).replace(".jpg", "");
            cv::imwrite(path.toStdString()+"/cut-"+std::string(str)+".jpg", crop);
            i = i+1;
        }

        void Document::createFolder()
        {
            QString path = QString::fromLocal8Bit(document_name.c_str()).replace(".jpg", "");
            if(!QDir(path).exists()) {
                QDir().mkdir(path);
            }

        }





    }
}
