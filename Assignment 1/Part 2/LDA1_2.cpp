#include <iostream>
// (Chapter 3) Ingredients Adjuster
int main () {
    const double sugarPerCookie = 1.5 / 48;
    const double butterPerCookie = 1.0 / 48;
    const double flourPerCookie = 2.75 / 48;

    int numberOfCookies;
    std::cout << "How many cookies do you want to bake? ";
    std::cin >> numberOfCookies;

    double sugarNeeded = sugarPerCookie * numberOfCookies;
    double butterNeeded = butterPerCookie * numberOfCookies;
    double flourNeeded = flourPerCookie * numberOfCookies;

    std::cout
        << "You need " << sugarNeeded << " cups of sugar, "
        << butterNeeded << " cups of butter, and "
        << flourNeeded << " cups of flour." << std::endl;

    return 0;
}
