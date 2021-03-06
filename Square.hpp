#pragma once
#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(Square&& other) = default;
    Square& operator=(Square&& other) = default;
    Square(const Square & other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    void print() const noexcept override;
    double getY() = delete; // should not have Y dimension
    Square() = delete;
};
