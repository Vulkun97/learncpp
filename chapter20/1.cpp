/*In this quiz, we’re going to write a version of our basic calculator using function pointers.

1a) Create a short program asking the user for two integer inputs and a mathematical operation (‘+’, ‘-‘, ‘*’, ‘/’). 
Ensure the user enters a valid operation.
1b) Write functions named add(), subtract(), multiply(), and divide(). 
These should take two integer parameters and return an integer.
1c) Create a type alias named ArithmeticFunction for a pointer to a function that takes two integer parameters and returns an integer. 
Use std::function, and include the appropriate header.
1d) Write a function named getArithmeticFunction() that takes an operator character and returns the appropriate function as a function pointer.
1e) Modify your main() function to call getArithmeticFunction(). 
Call the return value from that function with your inputs and print the result.*/

#include <array>
#include <string>
#include <string_view>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <utility>
#include <limits>
#include <functional>

namespace Calculator
{
    enum Operation{
    addition,
    substruction,
    multiplication,
    division,
    max_operation,
};

using ArithmeticFunction = std::function<int (int, int)>;

bool clear_input()
{
    bool correct_input {true};

    if(std::cin.fail())
    {
        correct_input = false;
        std::cin.clear();
    }
    if(std::cin.fail())
    {
        std::exit(0);
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return correct_input;
}

int getInt(){
    int input{};

    while(1)
    {
        std::cout<<"Enter an integer: ";
        std::cin>>input;

        if (!clear_input())
        {
            continue;
        }

        return input;
    }
}

Operation charToOperation (char input)
{
    switch (input)
    {
    case ('+'):
        return Operation::addition;
    case ('-'):
        return Operation::substruction;
    case ('*'):
        return Operation::multiplication;
    case ('/'):
        return Operation::division;
    default:
        return Operation::max_operation;
    }
}

char operationToChar (Operation operation)
{
    using enum Operation;

    switch (operation)
    {
    case addition:
        return '+';
    case substruction:
        return '-';
    case multiplication:
        return '*';
    case division:
        return '/';
    default:
        return '?';
    }
}

Operation getOperation()
{
    char input {};
    Operation operation {};

    while(1)
    {
        std::cout<<"Enter an operation (`+`, `-`, `*`, `/`): ";
        std::cin>>input;

        if (!clear_input())
        {
            continue;
        }

        operation = charToOperation(input);

        if(operation == Operation::max_operation)
        {
            continue;
        }

        return operation;
    }
}

int add(int x, int y)
{
    return x + y;
} 

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

ArithmeticFunction getArithmeticFunction(Operation operation)
{
    using enum Operation;

    switch (operation)
    {
    case addition:
        return add;
    case substruction:
        return subtract;
    case multiplication:
        return multiply;
    case division:
        return divide;
    default:
        return nullptr;
    }
}

std::ostream& operator<< (std::ostream& out, Operation operation)
{
    out<<operationToChar(operation);
    return out;
}
}



auto main() -> int
{
    int x {Calculator::getInt()};
    Calculator::Operation operation {Calculator::getOperation()};
    int y {Calculator::getInt()};
    Calculator::ArithmeticFunction fun {Calculator::getArithmeticFunction(operation)};
    if (fun)
    {
        std::cout<<x<<" "<<operation<<" "<<y<<" = "<<fun(x, y)<<std::endl;
    }
    
}
