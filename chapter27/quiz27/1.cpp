/*Write a Fraction class that has a constructor that takes a numerator and a denominator. 
If the user passes in a denominator of 0, throw an exception of type std::runtime_error (included in the stdexcept header). 
In your main program, ask the user to enter two integers. If the Fraction is valid, print the fraction. 
If the Fraction is invalid, catch a std::exception, and tell the user that they entered an invalid fraction.*/

#include <array>
#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <stdexcept>

class Fraction
{
    int m_numerator {};
    int m_denominator {};

public:
    Fraction (int numerator, int denominator)
    : m_numerator {numerator}
    , m_denominator {denominator}
    {
        if (denominator == 0)
            throw std::runtime_error("Invalid denominator");
    }

    friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction)
    {
        std::cout<<fraction.m_numerator<<"/"<<fraction.m_denominator;
        return out;
    }
};

int main()
{
    int numenator{};
    int denominator{};
    std::cout<<"Enter a numenator: ";
    std::cin>>numenator;
    std::cout<<"Enter a denominator: ";
    std::cin>>denominator;

    try
    {
        Fraction fraction {numenator, denominator};
        std::cout<<fraction;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
