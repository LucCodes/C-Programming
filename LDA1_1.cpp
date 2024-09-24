#include <iostream>
// Chapter 2: How Much Paint
// A particular brand of paint covers 340.0 square feet per gallon.   Write a program to determine and report approximately how many gallons of paint will need to paint two sides of fences with two coats on each wooden fence that is 6 feet high and 100 feet long.   
int main() {
    const double coverage_per_gallon = 340.0;
    const double fence_height = 6.0;
    const double fence_length = 100.0;
    const int number_of_sides = 2;
    const int number_of_coats = 2;

    double total_area = fence_height * fence_length * number_of_sides * number_of_coats;
    double gallons_needed = total_area / coverage_per_gallon;

    std::cout << "You will need approximately " << gallons_needed << " gallons of paint." << std::endl;

    return 0;
}

