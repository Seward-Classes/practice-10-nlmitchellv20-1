// AI Disclaimer: This program was written with moderate AI assistance. 
// Used AI for assistance with initial code and file structure. Also for suggestions to handle errors and debugging.
// Evaluated/tested code and made adjustments where needed to ensure that requirements were met and code ran successfully.

// Date: April 13, 2026
// Author: Nicki Mitchell

// Practice 10 - Shape Manager with Smart Pointers


#include "shape.h"
#include <iomanip>

void Shape::display() const {
    std::cout << "This is a Shape object." << std::endl;
}


Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

double Rectangle::getArea() const {
    return width * height;
}

void Rectangle::display() const {
    std::cout << "Rectangle (" << std::fixed << std::setprecision(1) << width << " x " << height << ")" << std::endl;
}

// Circle Implementation
Circle::Circle(double radius) : radius(radius) {}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

void Circle::display() const {
    std::cout << "Circle (radius: " << std::fixed << std::setprecision(1) << radius << ")" << std::endl;
}
