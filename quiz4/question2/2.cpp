/*Write the following program: The user is asked to enter 2 floating point numbers (use doubles). 
The user is then asked to enter one of the following mathematical symbols: +, -, *, or /. 
The program computes the answer on the two numbers the user entered and prints the results. 
If the user enters an invalid symbol, the program should print nothing.*/

#include <iostream>

int main()
{
    std::cout<<"Enter a float 1: ";

    double x{};
    std::cin>>x;

    std::cout<<"Enter a float 2: ";

    double y{};
    std::cin>>y;

    std::cout<<"Enter an operator: ";

    char c{};
    std::cin>>c;

    switch (c)
    {
    case '+':
        std::cout<<x<<" + "<<y<<" = "<<x+y<<std::endl;
        break;
    case '-':
        std::cout<<x<<" - "<<y<<" = "<<x-y<<std::endl;
        break;
    case '*':
        std::cout<<x<<" * "<<y<<" = "<<x*y<<std::endl;
        break;
    case '/':
        std::cout<<x<<" / "<<y<<" = "<<x/y<<std::endl;
        break;
    default:
        std::cout<<"Incorrect operator"<<std::endl;
        break;
    }

}