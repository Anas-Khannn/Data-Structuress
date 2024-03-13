#include<iostream>
using namespace std;

class Rectangle {
public:
    // Public data members
    double length;
    double width;

    // Constructor
    Rectangle(double l, double w) : length(l), width(w) {}

    // Function to calculate the area of the rectangle
    double calculateArea() {
        return length * width;
    }

    // Function to calculate the perimeter of the rectangle
    double calculatePerimeter() {
        return 2 * (length + width);
    }

    // Function to display information about the rectangle
    void displayInfo() {
        cout << "Rectangle: Length = " << length << ", Width = " << width << "\n";
        cout << "Area = " << calculateArea() << ", Perimeter = " << calculatePerimeter() << "\n";
    }
};

int main() {
    // Create a Rectangle object
    Rectangle myRectangle(5.0, 3.0);

    // Display information about the rectangle
    myRectangle.displayInfo();

    // Change the dimensions of the rectangle
    myRectangle.length = 8.0;
    myRectangle.width = 4.0;

    // Display updated information
    myRectangle.displayInfo();

    return 0;
}
