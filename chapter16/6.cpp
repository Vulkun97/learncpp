/*we implemented a game called FizzBuzz for the numbers three, five, and seven.

In this quiz, implement the game as follows:

Numbers divisible by only 3 should print “fizz”.
Numbers divisible by only 5 should print “buzz”.
Numbers divisible by only 7 should print “pop”.
Numbers divisible by only 11 should print “bang”.
Numbers divisible by only 13 should print “jazz”.
Numbers divisible by only 17 should print “pow”.
Numbers divisible by only 19 should print “boom”.
Numbers divisible by more than one of the above should print each of the words associated with its divisors.
Numbers not divisible by any of the above should just print the number.
Use a std::vector to hold the divisors, and another std::vector to hold the words (as type std::string_view). 
If the arrays do not have the same length, the program should assert. Produce output for 150 numbers.*/

#include <iostream>
#include <vector>
#include <string>

class FizzEtc{
    struct Pair {
        int number{};
        std::string_view word {};
    };

    std::vector<Pair> pairs {
        {3, "fizz"},
        {5, "buzz"},
        {7, "pop"},
        {11, "bang"},
        {13, "jazz"},
        {17, "pow"},
        {19, "boom"},
    };

    constexpr void Print(int number) const {
        bool temp {};
        for(std::size_t index{}; index < pairs.size(); index++){
            if (number % pairs[index].number == 0){
                std::cout<<pairs[index].word;
                temp = true;
            }   
        }

        if (!temp)
            std::cout<<number;
        
        std::cout<<'\n';
    }

public:
    constexpr void Play(int max) const{
        for(std::size_t index{1}; index < max; index++){
            Print(index);
        }
    }
};

int main(){
    FizzEtc game{};
    game.Play(150);
}