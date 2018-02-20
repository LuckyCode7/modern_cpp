#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    virtual double getX() const final;
    virtual double getY() const final;
    void print() const override;

private:
    Rectangle() = delete;

    double x_;
    double y_;
};
