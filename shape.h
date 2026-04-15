#pragma once
#define _USE_MATH_DEFINES // Essential for M_PI on some systems
#include <cmath>
#include <iostream>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual void display() const; 
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override { return width * height; }
    void display() const override {
        std::cout << "Rectangle (" << width << " x " << height << ")";
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override { 
        // Use a literal if M_PI fails, or just 3.14159265358979323846
        return M_PI * radius * radius; 
    }
    void display() const override {
        std::cout << "Circle (radius: " << radius << ")";
    }
};
