#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <cmath>

class Shape {
public:
    // Pure virtual function - derived classes must implement
    virtual double getArea() const = 0;
    
    // Virtual function - derived classes can override
    virtual void display() const;
    
    // Virtual destructor
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height);
    double getArea() const override;
    void display() const override;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius);
    double getArea() const override;
    void display() const override;
};

#endif