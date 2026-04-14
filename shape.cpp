#include "Shape.h"

void Shape::display() const {
    std::cout << "Basic Shape type";
}

void Rectangle::display() const {
    std::cout << "Rectangle (" << width << " x " << height << ")";
}

void Circle::display() const {
    std::cout << "Circle (radius: " << radius << ")";
}
