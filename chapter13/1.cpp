/*Define an enum class named Animal that contains the following animals: pig, chicken, goat, cat, dog, duck. 
Write a function named getAnimalName() that takes an Animal parameter and uses a switch statement 
to return the name for that animal as a std::string_view (or std::string if you’re using C++14). 
Write another function named printNumberOfLegs() that uses a switch statement to print the number 
of legs each animal walks on. Make sure both functions have a default case that prints an error message. 
Call printNumberOfLegs() from main() with a cat and a chicken. Your output should look like this:
A cat has 4 legs.
A chicken has 2 legs.*/

#include <iostream>

enum class Animal{
    pig,
    chiken,
    goat,
    cat,
    dog,
    duck,
};

std::string_view getAnimalName (const Animal& animal){
    switch (animal)
    {
    case Animal::pig:
        return "pig";
    case Animal::chiken:
        return "chiken";
    case Animal::goat:
        return "goat";
    case Animal::cat:
        return "cat";
    case Animal::dog:
        return "dog";
    case Animal::duck:
        return "duck";
    default:
        return "getAnimalName error";
    }
}

std::string_view printNumberOfLegs (const Animal& animal){
    switch (animal)
    {
    case Animal::pig:
        return "4";
    case Animal::chiken:
        return "2";
    case Animal::goat:
        return "4";
    case Animal::cat:
        return "4";
    case Animal::dog:
        return "4";
    case Animal::duck:
        return "2";
    default:
        return "printNumberOfLegs error";
    }
}

int main(){
    std::cout<<"A "<<getAnimalName(Animal::cat)<<" has "<<printNumberOfLegs(Animal::cat)<<" legs.\n";
    std::cout<<"A "<<getAnimalName(Animal::chiken)<<" has "<<printNumberOfLegs(Animal::chiken)<<" legs.\n";
}