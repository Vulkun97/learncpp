/*Declare a struct that represents your monster. 
The monster should have a type that can be one of the following: 
an ogre, a dragon, an orc, a giant spider, or a slime.

Each individual monster should also have a name (use a std::string or std::string_view),
 as well as an amount of health that represents how much damage they can take before they die. 
 Write a function named printMonster() that prints out all of the struct’s members. 
 Instantiate an ogre and a slime, initialize them using an initializer list, and pass them to printMonster().

Your program should produce the following output:

This Ogre is named Torg and has 145 health.
This Slime is named Blurp and has 23 health.*/

#include <iostream>
#include <string_view>

struct Monster {
    enum class Type{
    ogre, slime, dragon, giant_spider, orc,
    };

    Type monster_type {};
    std::string monster_name {};
    int monster_healf {100};
};


constexpr std::string_view getMonsterType (const Monster::Type& mt){
    using enum Monster::Type;

    switch (mt)
    {
    case ogre:
        return "Ogre";
    case slime:
        return "Slime";
    case dragon:
        return "Dragon";
    case giant_spider:
        return "Giant spider";
    case orc:
        return "Orc";

    default:
        return "???";
    }
}

constexpr void printMonster (const Monster& monster){
    std::cout<<"This "<<getMonsterType(monster.monster_type)<<
    " is named "<<monster.monster_name<<
    " and has "<<monster.monster_healf<<" health.\n";
    return;   
}

int main(){
    Monster m1 {Monster::Type::ogre, "Torg", 145};
    Monster m2 {Monster::Type::slime, "Blurp", 23};

    printMonster(m1);
    printMonster(m2);
}