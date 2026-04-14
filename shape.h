#pragma once
#include <iostream>
#include <string>
#include <cmath>

// Stage 1: Abstract Base Class
class Shape {
public:
    virtual ~Shape() = default; // Essential for proper cleanup of derived types
    virtual double getArea() const = 0; // Pure virtual: Makes class abstract
    virtual void display() const; 
};

// Stage 2: Rectangle Derived Class
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override { return width * height; }
    void display() const override;
};

// Stage 2: Circle Derived Class
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override { return M_PI * radius * radius; }
    void display() const override;
};
