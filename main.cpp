#include <iostream>
#include <string>

int main() {
    
}

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <string>

// Header first
#include "Shape.h"

// WORKAROUND: Including .cpp directly. 
// Note: If you do this, DO NOT list Shape.cpp in your compile command.
#include "Shape.cpp"

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->display();
        std::cout << "\nArea: " << std::fixed << std::setprecision(4) << shape->getArea() << "\n" << std::endl;
    }
}

int main() {
    std::ifstream file("shapes.txt");
    if (!file) {
        std::cerr << "Error: Could not open shapes.txt. Make sure the file exists in the root folder." << std::endl;
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
                std::cerr << "Line " << lineNumber << ": Invalid rectangle data." << std::endl;
            }
        } 
        else if (type == "circle") {
            double r;
            if (ss >> r) {
                shapes.push_back(std::make_unique<Circle>(r));
            } else {
                std::cerr << "Line " << lineNumber << ": Invalid circle data." << std::endl;
            }
        } 
        else {
            std::cerr << "Line " << lineNumber << ": Unknown shape type '" << type << "'" << std::endl;
        }
    }

    file.close();
    
    if (shapes.empty()) {
        std::cout << "No valid shapes were loaded from the file." << std::endl;
    } else {
        printAllAreas(shapes);
    }

    return 0;
}
