#ifndef BLOCKS_H
#define BLOCKS_H

namespace dynengines {
    namespace detector {
        class Blocks {

        public :
            Blocks();
            std::vector<cv::Rect> detect(cv::Mat img);
            //void on_trackbar(int, void*);

        private :
            const int alpha_slider_max = 100;
            int alpha_slider;
            double alpha;
            double beta;
        };
    }
}

#endif // BLOCKS_H
