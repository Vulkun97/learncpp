/*A floating point number is a number with a decimal where the number of digits after the decimal can be variable. 
A fixed point number is a number with a fractional component where the number of digits in the fractional portion is fixed.

In this quiz, we’re going to write a class to implement a fixed point number with two fractional digits (e.g. 12.34, 3.00, or 1278.99). 
Assume that the range of the class should be -32768.99 to 32767.99, that the fractional component should hold any two digits, 
that we don’t want precision errors, and that we want to conserve space.*/

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
#include <cinttypes>
#include <cmath>

class FixedPoint2
{
    std::int16_t m_base {0};
    std::int8_t m_fraction {0};

public:
    FixedPoint2(int base, int fraction) : m_base{static_cast<std::int16_t>(base)}, m_fraction{static_cast<std::int8_t>(fraction)} 
    {
        if (base < 0 || fraction < 0)
        {
            if (m_base > 0)
            {
                m_base = -m_base;
            }
            if (m_fraction > 0)
            {
                m_fraction = -m_fraction;
            }
        }

        m_base += m_fraction / 100;
        m_fraction = m_fraction % 100;
    }

    FixedPoint2(double double_number) : FixedPoint2(
        static_cast<std::int16_t>(static_cast<int>(std::round(double_number * 100)) / 100), 
        static_cast<std::int8_t>(static_cast<int>(std::round(double_number * 100)) % 100)
    ) {}

    explicit operator double() const
    {
        return m_base + (static_cast<double>(m_fraction) / 100);
    }

    friend bool operator== (const FixedPoint2& fp1, const FixedPoint2& fp2)
    {
        return fp1.m_base == fp2.m_base && fp1.m_fraction == fp2.m_fraction;
    }

    friend FixedPoint2 operator+ (const FixedPoint2& fp1, const FixedPoint2& fp2)
    {
        return (static_cast<double>(fp1) + static_cast<double>(fp2));
    }

    FixedPoint2 operator- ()
    {
        return FixedPoint2{-m_base, -m_fraction};
    }
};

std::ostream& operator<<  (std::ostream& out, const FixedPoint2& fp)
{
    std::cout<<static_cast<double>(fp);
    return out;
}

std::istream& operator>> (std::istream& in, FixedPoint2& fp)
    {
        double double_num {};
        std::cin>>double_num;
        fp = FixedPoint2{double_num};
        return in;
    }

int main()
{
	assert(FixedPoint2{ 0.75 } == FixedPoint2{ 0.75 });    // Test equality true
	assert(!(FixedPoint2{ 0.75 } == FixedPoint2{ 0.76 })); // Test equality false

	// Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 });    // both positive, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 });    // both positive, with decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }); // both negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }); // both negative, with decimal overflow

	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 });  // second negative, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 });  // second negative, possible decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 });   // first negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 });   // first negative, possible decimal overflow

	FixedPoint2 a{ -0.48 };
	assert(static_cast<double>(a) == -0.48);
	assert(static_cast<double>(-a) == 0.48);

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	assert(static_cast<double>(a) == 5.68);

	return 0;
}