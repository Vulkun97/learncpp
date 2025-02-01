#include <iostream>

// Function-like macro that evaluates to true if the type (or object) is equal to or smaller than
// the size of two memory addresses
#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))

struct double3
{
    double a;
    double b;
    double c;
};

struct double2
{
    double a;
    double b;
};

struct double1
{
    double a;
};

int main()
{
    std::cout << std::boolalpha; // print true or false rather than 1 or 0
    std::cout << isSmall(int) << '\n'; // true

    double d {};
    std::cout << isSmall(d) << '\n'; // true
    std::cout << isSmall(double3) << '\n'; // false
    std::cout << isSmall(double2) << '\n'; // false
    std::cout << isSmall(double1) << '\n'; // false

    return 0;
}