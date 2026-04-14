#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>

// Workaround as requested: Include implementation directly
#include "Shape.h"
#include "Shape.cpp"

// Stage 4: Function to display areas polymorphically
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->display(); // Calls derived version
        std::cout << "\nArea: " << std::fixed << std::setprecision(4) 
                  << shape->getArea() << "\n" << std::endl;
    }
}

int main() {
    // Stage 3: File Handling
    std::ifstream file("shapes.txt");
    if (!file) {
        std::cerr << "Error: shapes.txt not found." << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;
    int lineNum = 0;

    while (std::getline(file, line)) {
        lineNum++;
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "rectangle") {
            double w, h;
            if (ss >> w >> h) {
                shapes.push_back(std::make_unique<Rectangle>(w, h));
            } else {
                std::cerr << "Line " << lineNum << ": Invalid data for rectangle." << std::endl;
            }
        } 
        else if (type == "circle") {
            double r;
            if (ss >> r) {
                shapes.push_back(std::make_unique<Circle>(r));
            } else {
                std::cerr << "Line " << lineNum << ": Invalid data for circle." << std::endl;
            }
        } 
        else {
            std::cerr << "Line " << lineNum << ": Unknown shape type '" << type << "'" << std::endl;
        }
    }

    file.close();
    printAllAreas(shapes);

    return 0;
}
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
rectangle 10 4
circle 3
rectangle 2 8
circle 5
