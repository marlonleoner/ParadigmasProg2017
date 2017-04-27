#ifndef POINT_HEADER
#define POINT_HEADER

class Point {
    
    private:

        double x;
        double y;

    public:

        Point();

        Point(double x, double y);

        double getX();

        double getY();

        void move(double dx, double dy);

        double distanceTo(Point p);
};

#endif