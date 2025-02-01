/*Modify your solution to quiz 1. In this version, create a function template (not a normal function) 
called isValueInArray() that takes two parameters: a std::vector, and a value. 
The function should return true if the value is in the array, and false otherwise. 
Call the function from main() and pass it the array of names and the name the user entered.*/

#include <iostream>
#include <vector>
#include <string>

template<typename T>
bool isValueInArray(std::vector<T> arr, T value){
    for(const T& element : arr){
        if (element == value)
            return true;
    }
    return false;
}

auto main() -> int{
    std::vector<std::string_view> names {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::string guess {};
    std::cout<<"Enter a name ";
    std::cin>>guess;

    if(isValueInArray(names, static_cast<std::string_view>(guess)))
        std::cout<<guess<<" was found.\n";
    else
        std::cout<<guess<<" was not found.\n";

    return 0;
}