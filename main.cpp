#include <iostream>
#include <string>

int main() {
    
}
// AI Disclosure: This code was generated with assistance from an AI (Gemini) to demonstrate 
// polymorphism with smart pointers and file I/O in C++.

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>

// Temporary workaround as per instructions
#include "Shape.h"
#include "Shape.cpp"

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->display();
        std::cout << "\nArea: " << std::fixed << std::setprecision(4) << shape->getArea() << "\n\n";
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
    int lineNumber = 0;

    while (std::getline(file, line)) {
        lineNumber++;
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "rectangle") {
            double w, h;
            if (ss >> w >> h) {
                shapes.push_back(std::make_unique<Rectangle>(w, h));
            } else {
                std::cerr << "Line " << lineNumber << ": Invalid rectangle data.\n";
            }
        } 
        else if (type == "circle") {
            double r;
            if (ss >> r) {
                shapes.push_back(std::make_unique<Circle>(r));
            } else {
                std::cerr << "Line " << lineNumber << ": Invalid circle data.\n";
            }
        } 
        else {
            std::cerr << "Line " << lineNumber << ": Unknown shape type '" << type << "'\n";
        }
    }

    file.close();
    printAllAreas(shapes);

    return 0;
}
