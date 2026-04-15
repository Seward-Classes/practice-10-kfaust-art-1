#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <string>

// 1. Include the Header
#include "Shape.h"

// 2. The "Workaround": Only include the .cpp if you are 
// NOT compiling it separately in the terminal.
#include "Shape.cpp"

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    if (shapes.empty()) {
        std::cout << "No shapes found to display." << std::endl;
        return;
    }
    for (const auto& shape : shapes) {
        shape->display();
        std::cout << "\nArea: " << std::fixed << std::setprecision(4) 
                  << shape->getArea() << "\n" << std::endl;
    }
}

int main() {
    // 3. Ensure this filename is exactly lowercase in the sidebar
    std::ifstream file("shapes.txt");
    if (!file) {
        std::cerr << "Error: shapes.txt not found in " << std::string(getenv("PWD")) << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;
    int lineNum = 0;

    while (std::getline(file, line)) {
        lineNum++;
        if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) continue;

        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "rectangle") {
            double w, h;
            if (ss >> w >> h) {
                shapes.push_back(std::make_unique<Rectangle>(w, h));
            } else {
                std::cerr << "Line " << lineNum << ": Invalid data." << std::endl;
            }
        } 
        else if (type == "circle") {
            double r;
            if (ss >> r) {
                shapes.push_back(std::make_unique<Circle>(r));
            } else {
                std::cerr << "Line " << lineNum << ": Invalid data." << std::endl;
            }
        } 
    }

    file.close();
    printAllAreas(shapes);

    return 0;
}
