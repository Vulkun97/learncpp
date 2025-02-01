/*We implemented a game of Hi-Lo.

Update your previous solution to handle invalid guesses (e.g. ‘x’), 
out of bounds guesses (e.g. 0 or 101), or valid guesses that have extraneous characters (e.g. 43x). 
Also handle the user entering extra characters when the game asks them whether they want to play again.

Hint: Write a separate function to handle the user inputting their guess 
(along with the associated error handling).*/

#include <cstdlib>
#include <iostream>
#include <limits>
#include "Random.h"

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction()
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            exit(0); // Shut down the program now
        }

        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();     // And remove the bad input

        return true;
    }

    return false;
}

int get_guess(){
    while (true) // Loop until user enters a valid input
    {
        int guess{};
        std::cin >> guess;

        if (clearFailedExtraction())
        {
            std::cout << "Oops, that input is invalid.  Please try again.\n";
            continue;
        }

        if (guess < 1 || guess > 100)
		{
            std::cout << "Oops, that input is invalid.  Please try again.\n";
			ignoreLine();
			continue; // and try again
		}

        ignoreLine(); // Remove any extraneous input
        return guess;     // Return the value we extracted
    }
}

int main(){

    int guesses{7};
    int min_guess{1};
    int max_guess{100};

    int guess {};
    int guess_count {};

    char answer {'y'};

    while(answer == 'y'){
        guess_count = 1;

        std::cout<<"Let's play a game. I'm thinking of a number between 1 and 100. You have "<<guesses<<" tries to guess what it is.\n";

        int random_number {Random::get(min_guess, max_guess)};

        while (guess_count <= guesses){
            std::cout<<"Guess #"<<guess_count++<<": ";
            guess = get_guess();

            if (guess > random_number){
               std::cout<<"Your guess is too high.\n";
                continue;
            }
            else if (guess < random_number){
                std::cout<<"Your guess is too low.\n";
                continue;
            }

            break;
        }

        if(guess == random_number){
            std::cout<<"Correct! You win!\n";
        }
        else {
            std::cout<<"Sorry, you lose. The correct number was "<<random_number<<".\n";
        }

        answer = 'q';

        while (answer != 'y' && answer != 'n'){
            std::cout<<"Would you like to play again (y/n)? ";
            std::cin>>answer;
            ignoreLine();
        }
    }

    std::cout<<"Thank you for playing.\n";
    
    return 0;
}