// AI Disclaimer: This program was written with moderate AI assistance. 
// Used AI for assistance with initial code and file structure. Also for suggestions to handle errors and debugging.
// Evaluated/tested code and made adjustments where needed to ensure that requirements were met and code ran successfully.

// Date: April 13, 2026
// Author: Nicki Mitchell

// Practice 10 - Shape Manager with Smart Pointers

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>
#include "shape.h"
#include "shape.cpp"


int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    std::ifstream inputFile("shapes.txt");
    
    
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open shapes.txt" << std::endl;
        return 1;
    }
    
    std::string line;
    int lineNumber = 0;
    
    while (std::getline(inputFile, line)) {
        lineNumber++;
        
        
        if (line.empty()) {
            continue;
        }
        
        std::istringstream iss(line);
        std::string shapeType;
        
       
        if (!(iss >> shapeType)) {
            std::cerr << "Error on line " << lineNumber << ": Invalid format" << std::endl;
            continue;
        }
        
        try {
            if (shapeType == "rectangle") {
                double width, height;
                if (iss >> width >> height) {
                    shapes.push_back(std::make_unique<Rectangle>(width, height));
                } else {
                    std::cerr << "Error on line " << lineNumber << ": Rectangle requires width and height" << std::endl;
                }
            } else if (shapeType == "circle") {
                double radius;
                if (iss >> radius) {
                    shapes.push_back(std::make_unique<Circle>(radius));
                } else {
                    std::cerr << "Error on line " << lineNumber << ": Circle requires radius" << std::endl;
                }
            } else {
                std::cerr << "Error on line " << lineNumber << ": Unknown shape type '" << shapeType << "'" << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error on line " << lineNumber << ": " << e.what() << std::endl;
        }
    }
    
    inputFile.close();
    
    // Display all shapes and their areas
    for (const auto& shape : shapes) {
        shape->display();
        
        
        if (dynamic_cast<Rectangle*>(shape.get())) {
            std::cout << "Area: " << static_cast<int>(shape->getArea()) << std::endl;
        }
    
        else if (dynamic_cast<Circle*>(shape.get())) {
            std::cout << std::fixed << std::setprecision(4) << "Area: " << shape->getArea() << std::endl;
        }
        std::cout << std::endl;
    }
    
    
    
    return 0;
}

