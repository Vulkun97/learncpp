/*a) Write a class named Fraction that has an integer numerator and denominator member. 
Write a print() function that prints out the fraction.*/

/*b) Add overloaded multiplication operators to handle multiplication between a Fraction and integer, and between two Fractions. 
Use the friend function method.*/

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
#include <numeric>

class Fraction
{
    int m_numerator {};
    int m_denuminator {1};

public:
    Fraction (): Fraction(0, 1) {};
    explicit Fraction(int numerator, int denumenator) : m_numerator {numerator} 
    {
        if (denumenator)
            m_denuminator = denumenator;
        reduce();
    };

    void reduce()
    {
        int gcd {std::gcd( m_numerator, m_denuminator)};
        if (gcd)
        {
            m_numerator /= gcd;
            m_denuminator /= gcd;
        }
            
    };

    void print() const
    {
        std::cout<<m_numerator<<"/"<<m_denuminator;
    };

    friend Fraction operator* (const Fraction& a, const Fraction& b)
    {
        return (Fraction(a.m_numerator * b.m_numerator, a.m_denuminator * b.m_denuminator));
    }

    friend Fraction operator* (const Fraction& a, int b)
    {
        return Fraction (a.m_numerator * b, a.m_denuminator);
    }

    friend Fraction operator* (int a, const Fraction& b)
    {
        return b * a;
    }

    friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction)
    {
        fraction.print();
        return out;
    }

    friend std::istream& operator>> (std::istream& in, Fraction& fraction)
    {
        char c;
        in>>fraction.m_numerator>>c>>fraction.m_denuminator;
        return in;
    }

    friend bool operator== (const Fraction& f1, const Fraction& f2 )
    {
        return f1.m_numerator == f2.m_numerator && f1.m_denuminator == f2.m_denuminator;
    }

    friend bool operator!= (const Fraction& f1, const Fraction& f2 )
    {
        return !(f1 == f2);
    }

    friend bool operator> (const Fraction& f1, const Fraction& f2 )
    {
        int lcm {std::lcm(f1.m_denuminator, f2.m_denuminator)};
        return f1.m_numerator * lcm / f1.m_denuminator  > f2.m_numerator * lcm / f2.m_denuminator;
    }

    friend bool operator< (const Fraction& f1, const Fraction& f2 )
    {
        return f2 > f1;
    }

    friend bool operator<= (const Fraction& f1, const Fraction& f2 )
    {
        return !(f1 > f2);
    }

    friend bool operator>= (const Fraction& f1, const Fraction& f2 )
    {
        return !(f1 < f2);
    }

};

int main()
{
    Fraction f1{2, 5};
    f1.print();
    std::cout << "\n";

    Fraction f2{3, 8};
    f2.print();
    std::cout << "\n";

    Fraction f3{ f1 * f2 };
    f3.print();
    std::cout << "\n";

    Fraction f4{ f1 * 2 };
    f4.print();
    std::cout << "\n";

    Fraction f5{ 2 * f2 };
    f5.print();
    std::cout << "\n";

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();
    std::cout << "\n";

	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';

    return 0;
}