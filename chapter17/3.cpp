/*Define a namespace named Animal. 
Inside it, define an enum containing the following animals: 
chicken, dog, cat, elephant, duck, and snake. 
Also create a struct named Data to store each animal’s name, number of legs, and the sound it makes. 
Create a std::array of Data and fill out a Data element for each animal.

Ask the user to enter the name of an animal. 
If the name does not match the name of one of our animals, tell them so. 
Otherwise, print the data for that animal. 
Then print the data for all of the other animals that didn’t match their input.*/
#include <array>
#include <string>
#include <iostream>

namespace Animal
{
    enum Type
    {
        chiken, 
        dog, 
        cat, 
        elephant, 
        duck, 
        snake,
        max_animal,
    };

    struct Data
    {
        std::string_view name {};
        int legs {};
        std::string_view sound {};
    };

    std::array<Data, 6> data {{
        {"chiken", 2, "cluck"},
        {"dog", 4, "woof"},
        {"cat", 4, "meow"},
        {"elephant", 4, "pawoo"},
        {"duck", 2, "quack"},
        {"snake", 0, "hisss"},
    }};

    void printAnimal(const Data& elem)
    {
        std::cout<<"A "<<elem.name<<" has "<<elem.legs<<" legs and says "<<elem.sound<<"\n";
    }
}

auto main () -> int
{
    std::cout<<"Enter an animal: ";
    std::string animal{};
    std::cin>>animal;
    bool found {};
    for(Animal::Data elem: Animal::data)
    {
        if (animal == elem.name)
        {
            Animal::printAnimal(elem);
            found = true;
        }
    }
    if (!found){
        std::cout<<"That animal couldn't be found.\n";
    }  

    std::cout<<"\nHere is the data for the rest of the animals:\n";
    for(Animal::Data elem: Animal::data)
    {
        if (animal != elem.name)
        {
            Animal::printAnimal(elem);
        }
    }
}