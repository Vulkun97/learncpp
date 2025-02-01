/*Write a recursive function that takes an integer as input and 
returns the sum of each individual digit in the integer (e.g. 357 = 3 + 5 + 7 = 15). 
Print the answer for input 93427 (which is 25). Assume the input values are positive.*/

#include <iostream>

int sumOfdigits (int input)
{
    if (!input)
        return 0;

    return input % 10 + sumOfdigits(input / 10);
}

auto main() -> int
{
    std::cout<<sumOfdigits(93427);
}