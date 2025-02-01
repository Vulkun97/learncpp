/*Implement a game of Hi-Lo. 
First, your program should pick a random integer between 1 and 100. 
The user is given 7 tries to guess the number.

If the user does not guess the correct number, 
the program should tell them whether they guessed too high or too low. 
If the user guesses the right number, 
the program should tell them they won. If they run out of guesses, 
the program should tell them they lost, and what the correct number is. 
At the end of the game, the user should be asked if they want to play again. 
If the user doesn’t enter ‘y’ or ‘n’, ask them again.

For this quiz, assume the user enters a valid number.*/

#include <iostream>
#include "Random.h"

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
            std::cin>>guess;

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
        }
    }

    std::cout<<"Thank you for playing.\n";
    
    return 0;
}