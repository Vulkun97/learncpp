//Convert the following program from using a normal pointer to using std::unique_ptr where appropriate:

#include <iostream>
#include <memory>

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};

void printFraction(const std::unique_ptr<Fraction>& ptr)
{
	if (ptr)
		std::cout << *ptr << '\n';
	else
		std::cout << "No fraction\n";
}

int main()
{
	auto ptr{ std::make_unique<Fraction>(3, 5) };

	printFraction(ptr);

	return 0;
}