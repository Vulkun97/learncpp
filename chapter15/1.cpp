/*Write a class template named Triad that has 3 private data members with independent type template parameters. 
The class should have a constructor, access functions, and a print() member function that is defined outside the class.
Produce the output:
[1, 2, 3]
1
[1, 2.3, Hello]*/

#include <iostream>
#include <string>

template <typename T, typename U, typename K>
class Triad{
    T m_x {};
    U m_y {};
    K m_z {};

public:
    Triad (const T& x, const U& y, const K& z) : m_x {x}, m_y {y}, m_z {z} {}; 

    const T& first() const {return m_x;};

    const U& second() const {return m_y;};

    const K& third() const {return m_z;};

    void print() const;
};

template <typename T, typename U, typename K>
void Triad<T, U, K>::print() const {
    std::cout<<"["<<m_x<<", "<<m_y<<", "<<m_z<<"]";
}

int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

	return 0;
}