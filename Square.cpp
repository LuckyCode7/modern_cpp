#include "Square.hpp"
#include <iostream>

Square::Square(double x)
    : Rectangle(x, x)
{}

double Square::getArea() noexcept
{
    return getX() * getX();
}

double Square::getPerimeter() noexcept
{
    return 4 * getX();
}

void Square::print() noexcept
{
    std::cout << "Square:      x: " << getX() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
