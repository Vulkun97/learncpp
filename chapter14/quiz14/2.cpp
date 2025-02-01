/*Convert Fraction from a struct to a class. 
Convert all of the functions to (non-static) member functions.*/

#include <iostream>

class Fraction
{
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    Fraction() = default;

    explicit Fraction(int numerator, int denomenator) : m_numerator {numerator} {
        if (denomenator)
            m_denominator = denomenator;
    }

    Fraction multiply (const Fraction& fraction) const {
        return Fraction {m_numerator * fraction.m_numerator, m_denominator * fraction.m_denominator};
    }

    void print() const{
        std::cout << m_numerator << '/' << m_denominator << '\n';
    } 

};

Fraction makeFraction()
{
    int numerator {};
    int denominator {};
    
    std::cout << "Enter a value for numerator: ";
    std::cin >> numerator;
    std::cout << "Enter a value for denominator: ";
    std::cin >> denominator;
    std::cout << '\n';

    Fraction temp{numerator, denominator};

    return temp;
}


int main()
{
    Fraction f1{ makeFraction() };
    Fraction f2{ makeFraction() };

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).print();
    return 0;
}