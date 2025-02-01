/*Write a program that:

Asks the user how many names they wish to enter.
Dynamically allocates a std::string array.
Asks the user to enter each name.
Calls std::sort to sort the names
Prints the sorted list of names.*/

#include <array>
#include <string>
#include <string_view>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <utility>
#include <limits>

void clear_input()
{
    if(std::cin.fail())
    {
        std::cin.clear();
    }
    if(std::cin.fail())
    {
        std::exit(0);
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

auto main() -> int
{
    int length {};

    std::cout<<"How many names would you like to enter? ";
    std::cin>>length;
    
    clear_input();


    auto* names {new std::string [length]{}};

    for(std::size_t index {}; index < length; index++)
    {
        std::cout<<"Enter name #"<<index+1<<": ";
        std::getline(std::cin, names[index]);
    }

    std::sort(names, names+length);

    std::cout<<"Here is your sorted list:\n";
    for(std::size_t index {}; index < length; index++)
    {
        std::cout<<"Name #"<<index+1<<": "<<names[index]<<"\n";
    }
    
}