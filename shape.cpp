#include "Shape.h"
#include <iostream>

void Shape::display() const {
    std::cout << "Generic Shape";
}

void Rectangle::display() const {
    std::cout << "Rectangle (" << width << " x " << height << ")";
}

void Circle::display() const {
    std::cout << "Circle (radius: " << radius << ")";
}
