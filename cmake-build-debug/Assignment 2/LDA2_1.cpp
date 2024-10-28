#include <iostream>
using namespace std;

void displayMenu()
{
    cout << "Geometry Calculator" << endl;
    cout << "1. Calculate the area of a Circle" << endl;
    cout << "2. Calculate the area of a Rectangle" << endl;
    cout << "3. Calculate the area of a Triangle" << endl;
    cout << "4. Quit" << endl;
}

int main() //  main function
{
    int choice; //  variable declaration
    double radius, length, width, base, height, area; // even more variables

    displayMenu();
    cin >> choice;

    switch (choice) //  switch statement
    {
        case 1: // circle case
            cout << "Enter the radius of the circle: ";
            cin >> radius;
            if (radius < 0)
            {
                cout << "Invalid input. Please enter a positive number." << endl;
            }
            else
            {
                area = 3.14159 * radius * radius;
                cout << "The area of the circle is " << area << endl;
            }
            break;
        case 2: // rectangle case
            cout << "Enter the length of the rectangle: ";
            cin >> length;
            cout << "Enter the width of the rectangle: ";
            cin >> width;
            if (length < 0 || width < 0)
            {
                cout << "Invalid input. Please enter a positive number." << endl;
            }
            else
            {
                area = length * width;
                cout << "The area of the rectangle is " << area << endl;
            }
            break;
        case 3: // triangle case
            cout << "Enter the base of the triangle: ";
            cin >> base;
            cout << "Enter the height of the triangle: ";
            cin >> height;
            if (base < 0 || height < 0)
            {
                cout << "Invalid input. Please enter a positive number." << endl;
            }
            else
            {
                area = 0.5 * base * height;
                cout << "The area of the triangle is " << area << endl;
            }
            break;
        case 4: // quit
            break;
        default: // default case
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
    }

    return 0;
}

// done in 10 minutes, Lucas was here