/*A deck of cards has 52 unique cards (13 card ranks of 4 suits). 
Create enumerations for the card ranks (ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, jack, queen, king) and 
suits (clubs, diamonds, hearts, spades).*/
/*Each card will be represented by a struct named Card that contains a rank and a suit member
Create the struct and move the enums into it.*/

#include <array>
#include <string>
#include <string_view>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include "Random.h"

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

struct Card
{
    enum Rank
    {
        ace,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king,
        max_rank,
    };

    enum Suit
    {
        clabs,
        diamonds,
        hearts,
        spades,
        max_suit,
    };

    static constexpr std::array allRanks {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};
    static constexpr std::array allSuits {clabs, diamonds, hearts, spades};

    

    Rank rank{};
    Suit suit{};

    friend std::ostream& operator<<(std::ostream& out, const Card &card)
    {
        static constexpr std::array ranks {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', };
        static constexpr std::array suits {'C', 'D', 'H', 'S', };
        out <<ranks[card.rank]<<suits[card.suit];
        return out;
    }

    int value() const
    {
        static constexpr std::array rankValues { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
        return rankValues[rank];
    }
};

/*Next, let’s create our deck of cards. Create a class named Deck that contains a std::array of Cards. 
You can assume a deck is 52 Cards.

The Deck should have three functions:
    First, the default constructor should initialize the array of cards. 
You can use a ranged-for loop similar to the one in the main() 
function of the prior example to traverse through all the suits and ranks.
    Second, add a dealCard() function that returns the next card in the Deck by value. 
Since std::array is a fixed-size array, think about how you will keep track of where the next card is. 
This function should assert out if it is called when the Deck has gone through all the cards.
    Third, write a shuffle() member function that shuffles the deck.*/

class Deck
{
private:
    static constexpr int m_deck_size{52};
    std::array <Card, m_deck_size> m_deck{};
    std::size_t m_nextCardIndex {};

public:
    consteval Deck()
    {
        std::size_t index{};
        for (auto suit : Card::allSuits)
            for (auto rank : Card::allRanks)
            {
                m_deck[index].suit = suit;
                m_deck[index].rank = rank;
                index++;
            }
    }

    void shuffle()
    {
        std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
        std::size_t m_nextCardIndex = 0;
    }

    Card dealCard()
    {
        assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards");
        return m_deck[m_nextCardIndex++];
    }
};

namespace Settings
{
    constexpr int bustValue {21};
    constexpr int stopDraw {17};
}

struct Player
{
    int score{};
    int aces{};

    Card draw(Deck& deck)
    {
        Card card {deck.dealCard()};
        score += card.value();

        if (card.rank == Card::ace){
            aces++;
        }

        return card;
    }

    bool bust()
    {
        if (score > Settings::bustValue)
        {
            if (aces > 0)
            {
                aces--;
                score -= 10;
                std::cout<<"Score is too big. Ace becomes 1\nThe score now: "<<score<<"\n";
                return false;
            }
            return true;
        }
        return false;
    }
};

enum class Result
{
    win  = 1,
    lose = 0,
    tie  = -1,
};

bool getInput()
{
    static char input{};

    if (input == 's')
        return false;

    while(1){
        std::cout<<"\n(h) to hit, or (s) to stand: ";
        std::cin>>input;
        clear_input();

        if (input == 's')
            return false;
        if (input == 'h')
            return true;

        std::cout<<"Wrong input!\n";
    }
}

Result playBlackjack()
{
    Deck deck{};
    deck.shuffle();

    Player dealer{};
    Player player{};

    std::cout << "The dealer is showing: " << dealer.draw(deck) <<" ("<<dealer.score<<")\n";
    std::cout << "You are showing: " << player.draw(deck) <<" "<<player.draw(deck)<<" ("<<player.score<<")\n";

    char input{};
    Card card{};

    while (1)
    {
        bool playerContinue {getInput()};
        bool dealerContinue {dealer.score < Settings::stopDraw};

        if(playerContinue)
        {   
            card = player.draw(deck);
            std::cout<<"You were dealt "<<card<<". You now have: "<<player.score<<"\n";
        }
        else if (dealer.score > player.score)
        {
            std::cout<<"\nThe dealer has bigger score than you!\n";
            return Result::lose;
        }  

        if(player.bust())
        {
            std::cout<<"\nYou went bust!\n";
            return Result::lose;
        }

        if(dealer.score == player.score)
        {
            std::cout<<"\nYou and dealer have same scores!\n";
            return Result::tie;
        }
            
        if (dealerContinue)
        {
            card = dealer.draw(deck);
            std::cout<<"The dealer flips a "<<card<<". They now have: "<<dealer.score<<"\n";
        }
        else if (player.score > dealer.score)
        {
            std::cout<<"\nYou have bigger score than dealer!\n";
            return Result::win;
        }
            
        if(dealer.bust())
        {
            std::cout<<"\nDealer went bust!\n";
            return Result::win;
        }
            
        
    }
}



int main()
{
    Result result {playBlackjack()};

    if ( result == Result::win)
    {
        std::cout << "You win!\n";
    }
    else if (result == Result::lose)
    {
        std::cout << "You lose!\n";
    }
    else
    {
        std::cout << "It`s a tie!\n";
    }

    return 0;
}