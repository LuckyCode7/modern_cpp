#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include <memory>

using namespace std;
using Collection = vector<shared_ptr<Shape>>;

constexpr int fib(const int& n)
{
    if(n ==1 || n==2)
        return 1;
    else return fib(n-2) + fib(n-1);
}

auto sortByArea(shared_ptr<Shape> first, shared_ptr<Shape> second)
{
    if(first == nullptr || second == nullptr)
    {
        return false;
    }
    return (first->getArea() < second->getArea());
}

auto perimeterBiggerThan20(shared_ptr<Shape> s)
{
    if(s)
    {
        return (s->getPerimeter() > 20);
    }
    return false;
}

auto areaLessThan10(shared_ptr<Shape> s)
{
    if(s)
    {
        return (s->getArea() < 10);
    }
    return false;
}

void printCollectionElements(const Collection& collection)
{
    for(const auto& it : collection)
    {
        if(it != nullptr)
        {
            (it)->print();
        }
    }
}

void printAreas(const Collection& collection)
{
    for(const auto& it : collection)
    {
        if(it != nullptr)
        {
            cout << (it)->getArea() << std::endl;
        }
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(shared_ptr<Shape> s),
                                     std::string info)
{
    Collection::const_iterator iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

int main()
{
    Collection shapes
    {
      make_shared<Circle>(2.0),
      make_shared<Circle>(3.0),
      nullptr,
      make_shared<Circle>(4.0),
      make_shared<Rectangle>(10.0, 5.0),
      make_shared<Square>(3.0),
      make_shared<Circle>(4.0)
    };

    auto temp = make_shared<Square>(Square(77));
    shapes.push_back(move(temp));

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");

    cout<<Circle::getPI()<<endl;
    cout<<alignof(Circle)<<endl;

    return 0;
}

