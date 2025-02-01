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
#include <numeric>
#include "Random.h"

/*Our program is going to consist of 3 classes: a Creature class, a Player class, and a Monster class. 
Player and Monster both inherit from Creature.*/

/*Step 1
First create the Creature class. 
Creatures have 5 attributes: A name (std::string), a symbol (a char), an amount of health (int), 
the amount of damage they do per attack (int), and the amount of gold they are carrying (int). 
Implement these as class members. Write a full set of getters (a get function for each member). 
Add three other functions: 
void reduceHealth(int) reduces the Creature’s health by an integer amount. 
bool isDead() returns true when the Creature’s health is 0 or less. 
void addGold(int) adds gold to the Creature.*/

class Creature
{
protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};
public:
    const std::string&  getName()   const {return m_name;}
    char          getSymbol() const {return m_symbol;}
    int           getHealth() const {return m_health;}
    int           getDamage() const {return m_damage;}
    int           getGold()   const {return m_gold;}
public:
    Creature(std::string_view name, const char symbol, int health, int damage, int gold)
    : m_name{name}
    , m_symbol{symbol}
    , m_health {health}
    , m_damage {damage}
    , m_gold {gold}
    {}

    void reduceHealth(int damage) {m_health -= damage;}
    bool isDead() const {return m_health <= 0;}
    void addGold(int gold) {m_gold += gold;}
    void addHealth(int health) {m_health += health;}
    void addDamage(int damage) {m_damage += damage;}
};

/*Step 2
 Now we’re going to create the Player class. The Player class inherits from Creature. 
 Player has one additional member, the player’s level, which starts at 1. 
 The player has a custom name (entered by the user), uses symbol ‘@’, has 10 health, does 1 damage to start, and has no gold. 
 Write a function called levelUp() that increases the player’s level and damage by 1. 
 Also write a getter for the level member. 
 Finally, write a function called hasWon() that returns true if the player has reached level 20.*/

 class Player : public Creature
 {
protected:
    int m_level {1};
public:
    int getLevel() const {return m_level;}
public:
    Player(std::string_view name)
    : Creature(name, '@', 10, 1, 0)
    {}

    void levelUp()
    {
        ++m_level;
        ++m_damage;
    }

    bool hasWon() {return m_level >= 20;}
    
 };

/*Step 3
Next up is the Monster class. Monster also inherits from Creature. Monsters have no non-inherited member variables.
First, write an empty Monster class inheriting from Creature, and then add an enum inside the Monster class named Type 
that contains enumerators for the 3 monsters that we’ll have in this game: dragon, orc, and slime 
(you’ll also want a max_types enumerator).*/

/*Step 4
Write a Monster constructor, so we can create monsters. The Monster constructor should take a Type enum as a parameter, 
and then create a Monster with the appropriate stats for that kind of monster.

Because all of our monster attributes are predefined (not random or customized per creature), we can use a lookup table. 
Our lookup table will be a C-style array of Creature, where indexing the array with a Type will return the appropriate Creature for that Type.
Since this Creature table is specific to Monster, we can define it inside the Monster class as static inline Creature monsterData[] { }, initialized with our Creature elements.
Our Monster constructor is then easy: we can call the Creature copy constructor and pass it the appropriate Creature from our monsterData table.*/

/*Step 5
Add a static function to Monster named getRandomMonster(). 
This function should pick a random number from 0 to max_types-1 and return a monster (by value) with that Type.*/

class Monster : public Creature
{
public:
    enum Type
    {
        dragon,
        orc,
        slime,
        max_types,
    };

private:
    static inline Creature monsterData[] 
    {
        { "dragon", 'D', 20, 4, 100 },
        { "orc", 'o', 4, 2, 25 },
        { "slime", 's', 1, 1, 10 },
    };

    static_assert(std::size(monsterData) == max_types);

public:
    

    Monster(Type type)
    : Creature(monsterData[type])
    {}

    static Monster getRandomMonster() { return Monster{static_cast<Type>(Random::get(0, max_types - 1))}; }
};

/*Step 7
Implement potions.*/

class Potion
{
public:
    enum Size
    {
        small,
        medium,
        big,
        max_sizes,
    };

    enum Type
    {
        health,
        damage,
        poison,
        max_types,
    };

protected:
    Size m_size{};
    Type m_type{};

    const std::string getSize_s()
    {
        switch (m_size)
        {
        case small: return "small";
        case medium: return "medium";
        case big: return "big";
        default: return "???";
        }
    }

    const std::string getType_s()
    {
        switch (m_type)
        {
        case health: return "health";
        case damage: return "damage";
        case poison: return "poison";
        default: return "???";
        }
    }

public:
    Potion(Size size, Type type)
        : m_size{size}
        , m_type {type}
    {}

    static Potion getRandomPotion()
    {
        int size{Random::get(0, max_sizes - 1)};
        int type{Random::get(0, max_types - 1)};

        return Potion{static_cast<Size>(size), static_cast<Type>(type)};
    }

    static bool foundPotion() { return Random::get(0, 100) < 30; }

    const std::string getName()
    {
        return (getSize_s() + " potion of " + getType_s()); 
    }

    Type getType() {return m_type;};
    Size getSize() {return m_size;};
};

/*Step 6
Create 4 functions:
The main() function should handle game setup (creating the Player) and the main game loop.
fightMonster() handles the fight between the Player and a single Monster, including asking the player what they want to do, handling the run or fight cases.
attackMonster() handles the player attacking the monster, including leveling up.
attackPlayer() handles the monster attacking the player.*/

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

void drinkPotion(Player& player, Potion& potion)
{
    std::cout<<"You drank a "<<potion.getName()<<".\n";
    switch (potion.getType())
    {
    case Potion::health:
        switch (potion.getSize())
        {
        case Potion::small: player.addHealth(2); break;
        case Potion::medium: player.addHealth(3); break;
        case Potion::big: player.addHealth(5); break;
        default: break;
        }
        break;

    case Potion::damage:
        switch (potion.getSize())
        {
        case Potion::small: player.addDamage(1); break;
        case Potion::medium: player.addDamage(2); break;
        case Potion::big: player.addDamage(3); break;
        default: break;
        }
        break;

    case Potion::poison:
        switch (potion.getSize())
        {
        case Potion::small: player.addHealth(-1); break;
        case Potion::medium: player.addHealth(-2); break;
        case Potion::big: player.addHealth(-3); break;
        default: break;
        }
        break;
    
    default:
        break;
    }
}

void searchForPotion(Player& p)
{
    if(Potion::foundPotion())
    {
        std::cout<<"You found a mythical potion! ";
        char answer{};
        while(answer != 'y' && answer != 'n')
        {
            std::cout<<"Do you want to drink it?[y/n]: ";
            std::cin>>answer;
            clear_input();
        }

        if (answer == 'y')
        {
            Potion potion {Potion::getRandomPotion()};
            drinkPotion(p, potion);
        }
    }
}

void attackMonster(Player& p, Monster& m)
{
    if (p.isDead())
        return;

    m.reduceHealth(p.getDamage());
    std::cout<<"You hit the "<<m.getName()<<" for "<<p.getDamage()<<" damage.\n";
    if (m.isDead())
    {
        std::cout<<"The "<<m.getName()<<" is dead.\n";
        p.levelUp();
        std::cout<<"You leveled up ("<<p.getLevel()<<") ";
        std::cout<<" and found "<<m.getGold()<<" gold.\n";
        p.addGold(m.getGold());
        searchForPotion(p);
    }     
}

void attackPlayer(Player&p, Monster& m)
{
    if (m.isDead())
        return;

    p.reduceHealth(m.getDamage());
    std::cout<<"The "<<m.getName()<<" hit you for "<<m.getDamage()<<" damage.\n"; 
}

bool fleeMonster(Player&p, Monster& m)
{
    if (Random::get(0, 1))
    {
        std::cout<<"You successfully fled.\n";
        return true;
    }
    else
    {
        std::cout<<"You failed to flee.\n";
        return false;
    }
}

void fightMonster(Player& p)
{
    Monster m{Monster::getRandomMonster()};
    std::cout<<"You have encountered a "<<m.getName()<<" "<<m.getSymbol()<<"\n";

    char command{};
    while(!m.isDead() && !p.isDead())
    {
        std::cout<<"(R)un or (F)ight: ";
        std::cin>>command;
        clear_input();

        switch (command)
        {
        case 'f':
        case 'F':
            attackMonster(p, m);
            attackPlayer(p, m);
            break;

        case 'r':
        case 'R':
            if(fleeMonster(p, m))
                return;

            attackPlayer(p, m);
            break;
    
        default:
            break;
        }
    }       
}

int main()
{
    std::string playerName {};
    std::cout<<"Enter your name: ";
    std::cin>>playerName;
    std::cout<<"Welcome "<<playerName<<"\n";
	Player p{playerName};

    while(1)
    {
        fightMonster(p);

        if (p.hasWon())
        {
            std::cout<<"You won and returned with "<<p.getGold()<<" gold!\n";
            break;
        }

        if (p.isDead())
        {
            std::cout<<"You died at lvl "<<p.getLevel()<<" and with "<<p.getGold()<<" gold.\n";
            std::cout<<"Too bad you cant take it with you!\n";
            break;
        }
    }

	return 0;
}