#include <iostream>
#include "Random.h"

class Monster {

public:
    enum Type {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes,
    };

private:
    Type m_type {};
    std::string m_name {};
    std::string m_roar {};
    int m_hp {};

public:
    Monster (Type type, std::string_view name, std::string_view roar, int hp) :
    m_type {type}, m_name {name}, m_roar {roar}, m_hp {hp}
    {};

    constexpr std::string_view getTypeString() const {
        switch (m_type)
        {
        case dragon:    return "dragon";
        case goblin:    return "goblin";
        case ogre:      return "ogre";
        case orc:       return "orc";
        case skeleton:  return "skeleton";
        case troll:     return "troll";
        case vampire:   return "vampire";
        case zombie:    return "zombie";
        default:        return "???";
        }
    }

     void print() const;
};

void Monster::print() const{
    std::cout<<m_name<<" the "<<getTypeString();
    if (m_hp)
        std::cout<<" has "<<m_hp<<" hit points and says "<<m_roar<<".\n";
    else
        std::cout<<" is dead.\n";

}

namespace MonsterGenerator
{
    constexpr std::string_view getName(int x){
        switch (x)
        {
        case 0:     return "Mort";
        case 1:     return "Bones";
        case 2:     return "Nibblez";
        case 3:     return "Jorge";
        case 4:     return "Uog";
        case 5:     return "Blarg";
        default:    return "???";
        }
    }

    constexpr std::string_view getRoar(int x){
        switch (x)
        {
        case 0:     return "*rattle*";
        case 1:     return "*hiss*";
        case 2:     return "*ROAR*";
        case 3:     return "*bleh*";
        case 4:     return "*arrrrrr*";
        case 5:     return "*rrr*";
        default:    return "???";
        }
    }

    constexpr Monster generate(){
        return Monster{
            static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes - 1)), 
            getName(Random::get(0, 5)), 
            getRoar(Random::get(0, 5)), 
            Random::get(0, 100)};
    }
    
} // namespace MonsterGenerator


int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}