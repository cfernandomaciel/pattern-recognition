#ifndef OUTPUT_H
#define OUTPUT_H

#include "opencv2/opencv.hpp"

namespace dynengines {
    class Output {
    public :
        Output();
        void renderVideo();
        void transformImage();
        void renderImage();
    };
}

#endif // OUTPUT_H