#include <array>
#include <string>
#include <string_view>
#include <iostream>
#include <cstdlib>
#include "Random.h"

/*Create a Potion namespace containing an enum named Type containing the potion types. 
Create two std::array: an int array to hold the potion costs, and a std::string_view array to hold the potion names.

Also write a function named shop() that enumerates through the list of Potions and prints their numbers, names, and cost.*/

namespace Potion
{
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_type,
    };

    constexpr std::array cost { 20, 30, 12, 50 };
    static_assert(std::size(cost) == max_type);

    constexpr std::array<std::string_view, max_type> names {"healing", "mana", "speed", "invisibility"};
    static_assert(std::size(names) == max_type);

    constexpr std::array types {healing, mana, speed, invisibility};
    static_assert(std::size(types) == max_type);
};

/*Create a Player class to store the player’s name, potion inventory, and gold. 
Add the introductory and goodbye text for Roscoe’s emporium. Get the player’s name and randomize their gold.

Use the “Random.h” file in lesson 8.15 -- Global random numbers (Random.h) to make randomization easy.*/

class Player
{
    std::string m_name {};
    std::array<int, Potion::max_type> m_inventory {0, 0, 0, 0};
    int m_gold {};

public:
    void new_player()
    {
        std::cout<<"Enter your name: ";
        std::getline(std::cin >> std::ws, m_name);

        m_gold = Random::get(80, 120);

        std::cout<<"Hello, "<<m_name<<", you have "<<m_gold<<" gold.\n";
    }

    void change_gold(int ammount)
    {
        if (ammount > m_gold)
        {
            return;
        }
            
        m_gold += ammount;
    }

    int get_gold() const
    {
        return m_gold;
    }

    void add_potion(Potion::Type type)
    {
        m_inventory[type]++;
    }

    void print_inventory() const
    {
        std::cout<<"Your inventory:\n";
        for (auto type: Potion::types)
        {
            if (m_inventory[type])
            {
                std::cout<<m_inventory[type]<<"x potion of "<<Potion::names[type]<<"\n";
            }
        }
        std::cout<<"You have "<<get_gold()<<" gold remaining.\n";
    }
};

void shop(){
    std::cout<<"Here is our selection for today:\n";

    for(auto type: Potion::types)
    {
        std::cout<<type<<") "<<Potion::names[type]<<" costs "<<Potion::cost[type]<<"\n";
    }
}

/*Add the ability to purchase potions, handling invalid input (treat any extraneous input as a failure). 
Print the player’s inventory after they leave. The program should be complete after this step.

Make sure you test for the following cases:
User enters an invalid potion number (e.g. ‘d’)
User enters a valid potion number but with extraneous input (e.g. 2d, 25)*/

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

bool findPotion(Potion::Type type)
{
    for (Potion::Type t: Potion::types)
    {
        if (t == type)
        {
            return true;
        }
    }
    return false;
}

int charNumToInt(char c)
{
    return c - '0';
}

void open_shop(Player& player){
    char input {};
    std::cout<<"\nWelcome to Roscoe's potion emporium!\n\n";
    while (input != 'q')
    {   
        shop();
        std::cout<<"Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        std::cin>>input;

        if (findPotion(static_cast<Potion::Type>(charNumToInt(input))))
        {
            if (player.get_gold() > Potion::cost[charNumToInt(input)])
            {
                std::cout<<"You purchased a potion of "<<Potion::names[charNumToInt(input)]<<".\n";
                player.change_gold(-(Potion::cost[charNumToInt(input)]));
                player.add_potion(static_cast<Potion::Type>(charNumToInt(input)));
            }
            else
            {
                std::cout<<"You cannot afford that!\n";
            }
            std::cout<<"You have "<<player.get_gold()<<" gold.\n";
        }
        else if (input == 'q')
        {
            std::cout<<"\nThanks for shopping at Roscoe's potion emporium!\n";
            return;
        }
        else
        {
            std::cout<<"That is an invalid input. Try again.\n";
        }
        clear_input();
    }
}

int main()
{   
    
    Player player;
    player.new_player();
    open_shop(player);
    player.print_inventory();
}