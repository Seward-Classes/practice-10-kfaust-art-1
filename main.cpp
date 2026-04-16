/*
AI Disclosure: This code was developed with the assistance of an AI (Gemini) 
to implement polymorphism using modern C++ smart pointers and file parsing.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>  // Required for std::unique_ptr
#include "Shape.h"

// Temporary workaround:
#include "Shape.cpp"

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->display();
        std::cout << "Area: " << shape->getArea() << std::endl << std::endl;
    }
}

int main() {
    std::ifstream file("shapes.txt");
    if (!file) {
        std::cerr << "Error: Could not open shapes.txt" << std::endl;
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
                std::cerr << "Line " << lineNum << ": Invalid rectangle data." << std::endl;
            }
        } 
        else if (type == "circle") {
            double r;
            if (ss >> r) {
                shapes.push_back(std::make_unique<Circle>(r));
            } else {
                std::cerr << "Line " << lineNum << ": Invalid circle data." << std::endl;
            }
        } 
        else {
            std::cerr << "Line " << lineNum << ": Unknown shape type '" << type << "'" << std::endl;
        }
    }

    printAllAreas(shapes);

    // No manual 'delete' or '.clear()' needed! 
    // unique_ptr cleans up automatically when main returns.
    return 0;
}
