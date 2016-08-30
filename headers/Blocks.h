#ifndef BLOCKS_H
#define BLOCKS_H

namespace dynengines {
    namespace detector {
        class Blocks {

        public :
            Blocks();
            std::vector<cv::Rect> detect(cv::Mat img);
        };
    }
}

#endif // BLOCKS_H
