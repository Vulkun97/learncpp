/*Create a struct Student that stores the name and points of a student. 
Create an array of students and use std::max_element to find the student with the most points, 
then print that student’s name. std::max_element takes the begin and end of a list, 
and a function that takes 2 parameters and returns true if the first argument is less than the second.*/

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

struct Student
{
    std::string name{};
    int points {};
};

auto main() -> int
{
    std::array<Student, 8> arr{
    {   { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 },
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } }
    };

    auto maxPoints{
        [](Student x, Student y) -> bool {return x.points < y.points;}
    };

    auto bestStudent = std::max_element(arr.begin(), arr.end(), maxPoints);

    std::cout<<bestStudent->name<<" is the best student\n";
}