#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <cmath>

class Shape {
public:
    virtual ~Shape() = default; // Essential for smart pointers and inheritance
    virtual double getArea() const = 0; // Pure virtual
    virtual void display() const = 0;
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override { return width * height; }
    void display() const override {
        std::cout << "Rectangle (" << width << " x " << height << ")" << std::endl;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override { return M_PI * radius * radius; }
    void display() const override {
        std::cout << "Circle (radius: " << radius << ")" << std::endl;
    }
};

#endif
