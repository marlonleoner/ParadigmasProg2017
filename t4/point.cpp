#include <cmath>
#include <point.h>

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point::getX() {
    return this->x;
}

double Point::getY() {
    return this->y;
}

void Point::move(double dx, double dy) {
    x += dx;
    y += dy;
}

double Point::distanceTo(Point p) {
    return sqrt(pow(this->x - p.getX(), 2) + pow(this->y - p.getY(), 2));
}