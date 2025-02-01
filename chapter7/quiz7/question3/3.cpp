/*Write a function int accumulate(int x). 
This function should return the sum of all of the values of x 
that have been passed to this function.*/

#include <iostream>

constexpr int accumulate(const int x){
    static int sum{0};
    return sum = sum + x;
}

int main()
{
    std::cout << accumulate(4) << '\n'; // prints 4
    std::cout << accumulate(3) << '\n'; // prints 7
    std::cout << accumulate(2) << '\n'; // prints 9
    std::cout << accumulate(1) << '\n'; // prints 10

    return 0;
}