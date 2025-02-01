/*Create a program-defined enum (inside a namespace) containing the names of the following animals: 
chicken, dog, cat, elephant, duck, and snake. 
Define an array with an element for each of these animals, 
and use an initializer list to initialize each element to hold the number of legs that animal has. 
Assert that the array has the correct number of initializers.
Write a main() function that prints the number of legs an elephant has, using the enumerator.*/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

namespace Animals {
    enum Animals {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        enum_size,
    };

    const std::vector<int> legs{2, 4, 4, 4, 2, 0};
};

auto main() -> int{
    
    assert(Animals::enum_size == Animals::legs.size());

    std::cout<<"Elephant has "<<Animals::legs[Animals::elephant]<<" legs!\n";
}

