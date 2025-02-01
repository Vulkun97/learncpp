/*Write a program that asks the user to enter a positive integer, 
and then uses a recursive function to print out the binary representation for that number.*/

#include <iostream>

void intToBin(unsigned int input){

    if (!input)
        return;

    intToBin(input / 2);
    std::cout<<input % 2;
}

auto main() -> int
{
    int input{};
    std::cout<<"Enter an integer: ";
    std::cin>>input;

    std::cout<<"Binary representation is\n";
    intToBin(input);
}

