/*Define a struct named Item that contains two members: std::string_view name and int gold. 
Define a std::array and initialize it with 4 Item objects, explicitly specifying the element type for each initializer. 
Assume you may add additional elements to the std::array later.

The program should print the following:
A sword costs 5 gold.
A dagger costs 3 gold.
A club costs 2 gold.
A spear costs 7 gold.*/

#include <array>
#include <iostream>

struct Item
{
    std::string_view name {};
    int gold{};
};

template<std::size_t N>
void showWares (const std::array<Item, N> wares)
{
    for(const auto& item: wares)
        std::cout<<"A "<<item.name<<" costs "<<item.gold<<" gold.\n";
}

int main()
{
    std::array<Item, 4> wares 
    {
        Item{"sword", 5},
        Item{"dagger", 3},
        Item{"club", 2},
        Item{"spear", 7},
    };

    std::array<Item, 4> wares1 
    {{
        {"sword", 5},
        {"dagger", 3},
        {"club", 2},
        {"spear", 7},
    }};

    showWares(wares);

    showWares(wares1);
}