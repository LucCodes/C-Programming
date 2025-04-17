#include <iostream>
// Chapter 2: How Much Paint
// A particular brand of paint covers 340.0 square feet per gallon.   Write a program to determine and report approximately how many gallons of paint will need to paint two sides of fences with two coats on each wooden fence that is 6 feet high and 100 feet long.   
int main() {
    const double coveragePerGallon = 340.0;
    const double fenceHeight = 6.0;
    const double fenceLength = 100.0;
    const int numberOfSides = 2;
    const int numberOfCoats = 2;

    double total_area = fenceHeight * fenceLength * numberOfSides * numberOfCoats;
    double gallons_needed = total_area / coveragePerGallon;

    std::cout
        << gallons_needed << " gallons of paint are needed to paint." << std::endl;

    return 0;
}

