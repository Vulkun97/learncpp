/*Let’s say you’re writing a game where the player can hold 3 types of items: health potions, torches, and arrows.*/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

/*Define an unscoped enum in a namespace to identify the different types of items. 
Define an std::vector to store the number of each item type the player is carrying. 
The player should start with 1 health potion, 5 torches, and 10 arrows. 
Assert to make sure the array has the correct number of initializers.

Hint: Define a count enumerator and use it inside the assert.

The program should output the following:
You have 16 total items*/

/*Modify your program from the prior step so it now outputs:
    You have 1 health potion
    You have 5 torches
    You have 10 arrows
    You have 16 total items

Use a loop to print out the number of items and the item names for each inventory item. 
Handle proper pluralization of the names.*/


namespace Items
{
    enum Type
    {
        h_potion,
        torch,
        arrow,
        max_type,
    };

    std::string_view typeToStringSingular (Type type)
    {
        switch (type)
        {
        case h_potion:  return "health potion";
        case torch:     return "torch";
        case arrow:     return "arrow";
        default:        return "???";
        };
    }

    std::string_view typeToStringPlural (Type type)
    {
        switch (type)
        {
        case h_potion:  return "health potions";
        case torch:     return "torches";
        case arrow:     return "arrows";
        default:        return "???";
        };
    }
}


auto totalItems(const std::vector<int>& arr) -> int
{
    int total {0};
    for (auto elem: arr)
    {
        total += elem;
    }
    return total;
}



auto main() -> int
{   
    std::vector <int> inventory{1, 5, 10};

    assert(Items::max_type == inventory.size());

    for(std::size_t index {0}; index < inventory.size(); index++ )
    {
        if (inventory[index] != 1)
        {
            std::cout<<"You have "<<inventory[index]<<" "<<Items::typeToStringPlural(static_cast<Items::Type>(index));
        }
        else{
             std::cout<<"You have 1 "<<Items::typeToStringSingular(static_cast<Items::Type>(index));
        }
        std::cout<<"\n";
    }

    std::cout<<"You have "<<totalItems(inventory)<<" total items.\n";
}
