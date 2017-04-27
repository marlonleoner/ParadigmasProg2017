#include <circle.h>

Circle::Circle() {
    centro = Point(0.0, 0.0); 
    r = 0.0;
}

Circle::Circle(double x, double y, double r) {
    centro = Point(x, y);
    this->r = r;
}

double Circle::getRaio() {
    return r;
}

Point Circle::getCentro() {
    return centro;
}

double Circle::area() {
    return PI * r * r;
}

double Circle::distanceTo(Circle c) {
    return this->centro.distanceTo(c.getCentro()) - this->r - c.getRaio();
}

