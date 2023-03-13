#include <iostream>

// abstract class
class Shape {
public:
    virtual void draw() const = 0;    // pure virtual function
    virtual ~Shape() {}               // virtual destructor
};

// concrete class
class Circle : public Shape {
public:
    void draw() const override { std::cout << "Circle::draw() called " << std::endl; }
};

// class Triangle - concrete class
class Square : public Shape {
public:
    void draw() const override { std::cout << "Square::draw() called " << std::endl; }
};

// ShapeFactory - ceeate an interface for creating an object, but let subclasses decide which class to instantiate
class ShapeFactory{
public:
    virtual Shape* createShape() const = 0;    // pure virtual function
    virtual ~ShapeFactory() {}            // virtual destructor
};

// CircleFactory - concrete class
class CircleFactory : public ShapeFactory {
public:
    Shape* createShape() const override { return new Circle; }
};

// SquareFactory - concrete class
class SquareFactory : public ShapeFactory {
public:
    Shape* createShape() const override { return new Square; }
};

int main() {
    // create a circle factory
    ShapeFactory* cirleFactory = new CircleFactory();
    // create a circle object using the circle factory
    Shape *circle = cirleFactory->createShape();
    // draw the circle
    circle->draw();

    // delete the circle object
    delete circle;
    // delete the circle factory object
    delete cirleFactory;


    // create a square factory
    ShapeFactory* squareFactory = new SquareFactory();
    // create a square object using the square factory
    Shape *square = squareFactory->createShape();
    // draw the square
    square->draw();

    // delete the square object
    delete square;
    // delete the square factory object
    delete squareFactory;
    return 0;
}
