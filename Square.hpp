#pragma once
#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(const Square & other) = default;

    double getArea() noexcept;
    double getPerimeter() noexcept;
    void print() noexcept;
    double getY() = delete; // should not have Y dimension
    Square() = delete;
};
