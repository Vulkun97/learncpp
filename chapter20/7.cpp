/*We’re going to write a little game with square numbers (numbers which can be created by multiplying an integer with itself (1, 4, 9, 16, 25, …)).

To setup the game:
Ask the user to enter a number to start at (e.g. 3).
Ask the user how many values to generate.
Pick a random integer between 2 and 4. This is the multiplier.
Generate the number of values the user indicated. 
Begining with the starting number, each value should be the next square number, multiplied by the multiplier.

To play the game:
The user enters a guess.
If the guess matches any generated value, the value is removed from the list and the user gets to guess again.
If the user guesses all of the generated values, they win.
If the guess does not match a generated value, the user loses and the program tells them the nearest unguessed value.*/

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
#include "Random.h"

auto main() -> int
{
    int start{};
    std::cout<<"Start where? ";
    std::cin>>start;

    int count{};
    std::cout<<"How many? ";
    std::cin>>count;

    int multiplier {Random::get(2, 4)};

    std::vector<int> arr(count);

    std::for_each(arr.begin(), arr.end(), 
    [multiplier, base = start](int& i) mutable  -> void 
    {
        i = (base * base) * multiplier; 
        base++;
    }
    );

    std::cout<<"I generated "<<count<<" square numbers. Do you know what each number is after multiplying it by "<<multiplier<<"?\n";

    int guess{};
    std::vector<int>::iterator element{};
    
    while (!arr.empty())
    {
        std::cout<<"> ";
        std::cin>>guess;
        element = std::find(arr.begin(), arr.end(), guess);

        if(element == arr.end())
        {
            std::cout<<guess<<" is wrong! Try "<<
            *(std::min_element(arr.begin(), arr.end(), 
            [=](int x, int y)
            {
                return abs(x - guess) < abs(y - guess);
            }
            ))
            <<" next time.\n";
            return 1;
        }

        arr.erase(element);
        std::cout<<"Nice! "<<--count<<" numbers left!\n";
    }

    std::cout<<"Nice! You found all numbers, good job!\n";
    return 0;
}