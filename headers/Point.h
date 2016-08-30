#ifndef POINT_H
#define POINT_H

#include <math.h>

namespace dynengines {
    namespace geometry {
        class Point {
        public :
            Point::Point(double x = 0.0, double y = 0.0) {
                xval = x;
                yval = y;
            }

            // Extractors.
            double x() { return xval; }
            double y() { return yval; }

            double dist(Point other);

            Point add(Point b);
            Point sub(Point b);
            void move(double a, double b);


        private :
             double xval, yval;
        };

    }
}

#endif // POINT_H
