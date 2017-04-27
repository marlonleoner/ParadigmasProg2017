#include <point.h>

const double PI = 3.14159;

#ifndef CIRCLE_HEADER
#define CIRCLE_HEADER

class Circle {

    private:

        Point centro;
        double r;

    public:

        Circle();

        Circle(double x, double y, double r);

        double getRaio();

        Point getCentro();

        double area();

        double distanceTo(Circle c);
};

#endif