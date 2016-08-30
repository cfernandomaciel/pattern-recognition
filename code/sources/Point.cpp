#include "headers/Point.h"

namespace dynengines {
    namespace geometry {

        double Point::dist(Point other) {
            double xd = xval - other.xval;
            double yd = yval - other.yval;

            return sqrt(xd*xd + yd*yd);
        }

        Point Point::add(Point b) {
             return Point(xval + b.xval, yval + b.yval);
        }

        Point Point::sub(Point b) {
            return Point(xval - b.xval, yval - b.yval);
        }

        void Point::move(double a, double b) {
            xval += a;
            yval += b;
        }

    }
}
