#pragma once
#include <iostream>
#include <string>

class Shape {
public:
    virtual ~Shape() = default; // Essential for virtual classes
    virtual double getArea() const = 0; // Pure virtual
    virtual void display() const; 
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override { return width * height; }
    void display() const override;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override { return 3.141592653589793 * radius * radius; }
    void display() const override;
};
