/*Write a class named MyString that holds a std::string. Overload operator<< to output the string. 
Overload operator() to return the substring that starts at the index of the first parameter (as a MyString). 
The length of the substring should be defined by the second parameter.*/

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

class MyString
{
    std::string m_string{};
public:
    MyString(std::string_view string) : m_string {string} {};

    friend std::ostream& operator<< (std::ostream& out, const MyString& string)
    {
        out<<string.m_string;
        return out;
    };

    MyString operator() (int pos, int count)
    {
        return MyString{ std::string_view{m_string}.substr(pos, count)};
    };
};

int main()
{
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}