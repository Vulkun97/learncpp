#include <iostream>
#include <vector>
#include "Random.h"
#include <algorithm>

class Card
{

public:

    enum Suits
    {
        clubs, diamonds, hearts, spades, max_suit,
    };

    enum Ranks
    {
        Ace, two, three, four, five, six, seven, eight, nine, ten, Jack, Queen, King, max_rank,
    };

    Suits m_suit {};
    Ranks m_rank {};
    
public:

    Card(Suits suit, Ranks rank) : m_suit{suit}, m_rank{rank}
    {};
    
    Card()
    {};

    bool print_suit() const
    {
        switch (m_suit)
        {
        case clubs:     std::cout<<"♣"; break;
        case diamonds:  std::cout<<"♦"; break;
        case hearts:    std::cout<<"♥"; break;
        case spades:    std::cout<<"♠"; break;
        default: return false;
        }

        return true;
    }

    bool print_rank() const
    {
        switch (m_rank)
        {
        case Ace:     std::cout<<"A"; break;
        case two:  std::cout<<"2"; break;
        case three:    std::cout<<"3"; break;
        case four:    std::cout<<"4"; break;
        case five:    std::cout<<"5"; break;
        case six:    std::cout<<"6"; break;
        case seven:    std::cout<<"7"; break;
        case eight:    std::cout<<"8"; break;
        case nine:    std::cout<<"9"; break;
        case ten:    std::cout<<"10"; break;
        case Jack:    std::cout<<"J"; break;
        case Queen:    std::cout<<"Q"; break;
        case King:    std::cout<<"K"; break;
        default: return false;
        }

        return true;
    }
    /*void print() const
    {
        std::cout<<"┌───┐\n";
        std::cout<<"│"; print_suit(); std::cout<<"  │\n";
        std::cout<<"│   │\n";

        if (m_rank == Ranks::ten)
            std::cout<<"│ ";
        else
            std::cout<<"│  ";

        print_rank(); std::cout<<"│\n"; 
        std::cout<<"└───┘\n";
    }*/

    void print() const
    {
        std::cout<<"[";
        print_suit();
        print_rank();
        std::cout<<"]";
    }

    friend std::ostream& operator<< (std::ostream& out, Card card)
    {
        card.print();
        return out;
    }

    bool valid()
    {
        switch (m_suit)
        {
        case clubs:     
        case diamonds:  
        case hearts:    
        case spades:    break;
        default: return false;
        }

        switch (m_rank)
        {
        case Ace:
        case two:
        case three:
        case four:
        case five:
        case six:
        case seven:
        case eight:
        case nine:
        case ten:
        case Jack:
        case Queen:
        case King:  return true;
        default:    return false;   
        }
    }

    bool cmp(const Card& card2) const
    {
        if(m_suit == card2.m_suit || m_rank == card2.m_rank)
            return true;
        return false;
    }
};

class CardsSet
{
protected:
    int m_size{};

    std::vector<Card> set {std::vector<Card>(m_size)};  

public:
    CardsSet(int size) : m_size {size}
    {}

    void print() const
    {
        int index {0};
        for (const auto& card : set)
        {
            card.print();

            if (card.m_rank == Card::ten)
                std::cout<<" ";
            else
                std::cout<<"  ";

            if (++index > 12)
            {
                index = 0;
                std::cout<<"\n";
            }
        }

        std::cout<<"\n";
    }

    bool empty() const
    {
        return !set.size() > 0;
    }

    Card popCard()
    {
        if (empty())
        {
            return Card {Card::max_suit, Card::max_rank};
        }

        Card card {set.back()};
        set.pop_back();
        --m_size;
        return card;
    }

    void pushCard(const Card& card)
    {
        ++m_size;
        set.push_back(card);
    }

    friend void operator+=(CardsSet& s1, CardsSet& s2)
    {
        while(!s2.empty())
        {
            s1.pushCard(s2.popCard());
        }
    }

    friend void operator<<(CardsSet& s1, CardsSet& s2)
    {
        s1.pushCard(s2.popCard());
    }

    friend void operator<<(CardsSet& s1, Card c1)
    {
        s1.pushCard(c1);
    }

    friend void operator<<(Card& c1, CardsSet& s1)
    {
        c1 = s1.popCard();
    }

    friend void moveCards(CardsSet& s1, CardsSet& s2, int ammount)
    {   
        //std::cout<<s2.m_size;
        if (s2.m_size >= ammount)
        {
            for (int i {0}; i < ammount; ++i)
            {
                s1<<s2;
            }

            s1.m_size += ammount;
            s2.m_size -= ammount;
        }
    }

    int getSize()
    {
        return m_size;
    }

    const Card& lastCard()const
    {
        return set.back();
    }
        
};

class Deck : public CardsSet
{

    static const int DECK_SIZE {static_cast<int>(Card::max_rank) * static_cast<int>(Card::max_suit)};

    void populate()
    {
        std::size_t index{};
        for (int suit {Card::clubs}; suit < Card::max_suit; ++suit)
        {
            for (int rank {Card::Ace}; rank < Card::max_rank; ++rank)
            {
                set[index].m_suit = static_cast<Card::Suits>(suit);
                set[index].m_rank = static_cast<Card::Ranks>(rank);
                ++index;
            }
        }
    }  

public:
    Deck(): CardsSet(DECK_SIZE)
    {
        populate();
    }

    void shuffle()
    {
        std::shuffle(std::begin(set), std::end(set), Random::mt);
    }

    
};

class Player : public CardsSet
{
public:
    Player() : CardsSet(0)
    {
    }

    const Card& showCard(int index)const
    {
        return set[index];
    }

    Card getCard(int index)
    {
        Card temp {set[index]};
        set.erase(set.begin() + index);
        --m_size;
        return temp;
    }
};

int main()
{
    Deck deck;
    CardsSet discardPile{0};

    deck.shuffle();

    int player_count{2};

    std::vector<Player> players{player_count};
    
    moveCards(players[0], deck, 5);
    moveCards(players[1], deck, 5);

    int player{0};

    char action{};

    Card last_card{};
    
    while(1)
    {
        for (int player{0}; player < player_count; ++player)
        {
            for (int i {0}; i < 25; i++)
            {
                std::cout<<"\n";
            }

            
            std::cout<<"\nPlayer "<<player+1<<" turn!\n";

            while(1)
            {
                if (!discardPile.empty())
                    std::cout<<"Card on top is "<<discardPile.lastCard();

                std::cout<<"\nChoose your next action:\nl) look at your hand \np) take a card from a deck\ns) skip turn\n1-5) put a card on a table\n";
                std::cin>>action;
                switch (action)
                {
                case 'l': players[player].print(); continue;

                case 'p':
                    if (players[player].getSize() < 5 && !deck.empty())
                        players[player] << deck;
                    else if (players[player].getSize() > 5)
                    {
                        std::cout<<"Your hand is full!\n";
                    }
                    else
                    {
                        std::cout<<"Deck is empty!\n";
                    }

                    continue;

                case 's':
                    break;

                case '1' ... '5':
                    if (discardPile.empty() || players[player].showCard(action-1-'0').cmp(discardPile.lastCard()))
                    {
                        discardPile<<players[player].getCard(action-1-'0');
                        break;
                    }
                    else
                    {
                        std::cout<<"Invalid card!\n";
                        continue;
                    }
            
                default: std::cout<<"Wrong action!\n"; continue;
                }

                break;
            }

            if (deck.empty())
            {
                last_card<<discardPile;

                deck+=discardPile;

                deck.shuffle();

                discardPile<<last_card;
            }

            if (players[player].empty())
            {
                std::cout<<"Congratulation! You won!\n";
                goto end;
            } 
        }  
    }

    end:

    return 0;
}