#include "Shape.h"
#ifndef POLYGON_H
#define POLYGON_H

class Polygon: public Shape{
    public:
        Polygon();
        ~Polygon();
        Polygon(Point* dots, int n);
        std::string getType();
        double area();
        double circumreference();
        bool isConvex();
        Point position();

    private:
    Point* d;
    int nums;
};

#endif