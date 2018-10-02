#pragma once
#include "Shape.hpp"

class alignas(128) Circle final : public Shape
{
public:
    Circle(double r);
    Circle(double r, Color c);
    Circle(const Circle & other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;
    Circle() = delete; // doesn't allow to call default constructor
    [[deprecated("deprecated method")]]
    static long double getPI();
private:
    double r_;
};
