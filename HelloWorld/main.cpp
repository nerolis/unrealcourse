#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

// Func Proto
void GameIntro();
void PlayGame();
void GameSummery();
FText GetValidGuess();
bool PlayAgain();

FBullCowGame BCGame; // Game class

int main()
{
    do {
        GameIntro();
        PlayGame();
    }
    while (PlayAgain());

    return 0;
}

void GameIntro()
{
    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << std::endl;
    std::cout << "          }   {         ___ " << std::endl;
    std::cout << "          (o o)        (o o) " << std::endl;
    std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
    std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
    std::cout << " *  |-,--- |              |------|  * " << std::endl;
    std::cout << "    ^      ^              ^      ^ " << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();

    while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
        FText Guess = GetValidGuess();
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << " Cows = " << BullCowCount.Cows << std::endl;
        std::cout << std::endl;
    }

    GameSummery();
    return;
}

FText GetValidGuess()
{
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    FText Guess = "";
    do {
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
        std::cout << ". Enter your guess: "  << std::endl;
        getline(std::cin, Guess);
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n\n";
                break;

            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter a word without repeating letters \n\n";
                break;

            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter all lowercase letters \n\n";
                break;

            default:
                break;
        }
    } while (Status != EGuessStatus:: OK); // Keep looping until we get a valid input;
    return Guess;
}

bool PlayAgain() 
{
    std::cout << "Do you want to play again with the same hidden word? Y/N?" << std::endl;
    FText Choice = "";
    getline(std:: cin, Choice);
    std::cout << std::endl;
    return (Choice[0] == 'y' || (Choice[0] == 'Y'));
}

void GameSummery()
{
    if(BCGame.IsGameWon())
    {
        std::cout << "Well done – you win" << std::endl;
    } else {
        std::cout << "The game is over – you lose" << std::endl;
    }
    std::cout << std::endl;
}
