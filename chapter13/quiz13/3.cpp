/*Create a class template named Triad 
that has 3 members of the same template type. 
Also create a function template named print that can print a Triad. 
The program should produce the following result:

[1, 2, 3][1.2, 3.4, 5.6]*/

#include <iostream>

template<typename T>
struct Triad{
    T elem1 {};
    T elem2 {};
    T elem3 {};
};

template <typename T>
constexpr void print(const Triad<T>& triad){
    std::cout<<"["<<triad.elem1<<
    ", "<<triad.elem2<<
    ", "<<triad.elem3<<"]";
}

int main()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}