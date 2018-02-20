#pragma once

enum class Color
{
    RED,
    GREEN,
    BLUE
};

class Shape
{
public:
    virtual ~Shape() {}

    virtual double getArea() const noexcept = 0;
    virtual double getPerimeter() const noexcept = 0;
    virtual void print() const;

private:
    Color c_ = Color::RED;
};
