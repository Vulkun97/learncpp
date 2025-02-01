/*Let’s implement the game C++man (which will be our version of the classic children’s lynching game Hangman.*/

/*a) Goals:
We’ll start by defining our list of words and writing a random word picker. 
You can use the Random.h from lesson 8.15 -- Global random numbers (Random.h) to assist.
Tasks:
First define a namespace named WordList. The starter list of words is: 
“mystery”, “broccoli” , “account”, “almost”, “spaghetti”, “opinion”, “beautiful”, “distance”, “luggage”. 
You can add others if you like.
Write a function to pick a random word and display the word picked. 
Run the program several times to make sure the word is randomized.
Here is a sample output from this step:

Welcome to C++man (a variant of Hangman)
To win: guess the word.  To lose: run out of pluses.
The word is: broccoli*/

/*b)Goals:
Be able to draw the basic state of the game, showing the word as underscores.
Accept a letter of input from the user, with basic error validation.
In this step, we will not yet keep track of which letters the user has entered.

Tasks:
Create a class named Session that will be used to store all of the data the game needs to manage in a game session. 
For now, we just need to know what the random word is.
Create a function to display the basic state of the game, where the word is displayed as underscores.
Create a function to accept a letter of input from the user. 
Do basic input validation to filter out non-letters or extraneous input.*/

/*c)Now that we can display some game state and get input from the user, let’s integrate that user input into the game.

Goals:
Keep track of which letters the user has guessed.
Display correctly guessed letters.
Implement a basic game loop.

Tasks:
Update the Session class to track which letters have been guessed so far.
Modify the game state function to display both underscores and correctly guessed letters.
Update the input routine to reject letters that have already been guessed.
Write a loop that executes 6 times before quitting (so we can test the above).
In this step, we will not tell the user whether the letter they guessed is in the word (but we will show it as part of the game state display).

The tricky part of this step is deciding how to store information on which letters the user has guessed. 
There are several different viable ways to do this. A hint: there are a fixed number of letters, and you’re going to be doing this a lot.*/

/*d)Goal: Finish the game.

Tasks:
Add in display of total wrong guesses left
Add in display of incorrect letters guessed
Add in win/loss condition and win/loss text.*/

#include <iostream>
#include <vector>
#include "Random.h"
#include <string>
#include <limits>

namespace WordList
{
    std::vector<std::string_view> words {
        "mystery",
        "broccoli",
        "account",
        "almost",
        "spaghetti",
        "opinion",
        "beautiful",
        "distance",
        "luggage",
    };

    std::string_view getWord()
    {
        return words[Random::get<std::size_t>(0, words.size() - 1)];
    }
}

class Session {
    std::string m_word {};
    std::vector<bool> m_guesses{std::vector<bool>(26)};
    int m_wrongGuessesLeft{10};

    bool inGusses(char c) const {return m_guesses[(c%32) - 1];}

    void printAttempts() const
    {
        for (int i; i < m_wrongGuessesLeft; i++)
        {
            std::cout<<"+";
        }
    }

    bool inWord(char c) const
    {
        for(char e: m_word)
            if (c == e)
                return true;
        return false;
    }

    void printGuesses() const
    {
        char guess {};
        for(std::size_t i{}; i < m_guesses.size(); i++)
        {
            guess = static_cast<char>(i+'a');

            if(m_guesses[i] && !inWord(guess))
            {
                std::cout<<guess;
            }
        }
    }

    bool isWon() const
    {
        bool won {true};

        for (char e: m_word)
        {
            if (!inGusses(e))
                won = false;
        }

        return won;
    }

    bool isLost() const
    {
        if (m_wrongGuessesLeft == 0)
            return true;
        return false;
    }


    
public:
    Session (std::string_view word) : Session(word, 10) {};
    Session (std::string_view word, int guesses) : m_word{word}, m_wrongGuessesLeft {guesses} {};

    std::string_view getWord() const {return m_word;}

    void draw() const
    {
        std::cout<<"The word: ";

        for (char c : m_word)
            if (inGusses(c))
                std::cout<<c;
            else
                std::cout<<"_";

        std::cout<<"\tWrong guesses: ";
        printAttempts();
        printGuesses();
        std::cout<<"\n";
    }

    void getGuess()
    {
        char input {};
        while (1)
        {
            std::cout<<"Enter your next letter: ";

            std::cin>>input;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (input < 'a' || input > 'z' || inGusses(input)) 
            {
                std::cout<<"That wasn't a valid input.  Try again.\n";
                continue;
            }

            if (!inWord(input))
                m_wrongGuessesLeft--;

            m_guesses[input%32-1] = true;
            return;
        }
    }

    bool continueGame ()
    {
        if (isWon()){
            std::cout<<"Congratulations! You won!";
            return false;
        }
        if (isLost()){
            std::cout<<"Too bad! You lost!\n";
            std::cout<<"Word was: "<<getWord()<<"\n";
            return false;
        }

        return true;
    }
};



auto main() -> int
{
    std::cout<<"Welcome to C++man (a variant of Hangman)\nTo win: guess the word.  To lose: run out of pluses.\n";
    //std::cout<<"The word is "<<WordList::getWord()<<"\n";

    Session game(WordList::getWord(), 6);
    game.draw();

    while (game.continueGame())
    {
        game.getGuess();
        game.draw();
    }
    

    
}