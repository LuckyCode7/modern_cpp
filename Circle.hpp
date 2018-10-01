#pragma once
#include "Shape.hpp"

class Circle : public Shape
{
public:
    Circle(double r);
    Circle(const Circle & other) = default;

    double getArea() const;
    double getPerimeter() const;
    double getRadius() const;
    void print() const;
    Circle() = delete; // doesn't allow to call default constructor
private:
    double r_;
};
