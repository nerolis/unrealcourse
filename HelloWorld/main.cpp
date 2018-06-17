#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

// Func Proto
void GameIntro();
void PlayGame();
FText GetGuess();
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

// Get a Guess from the Player
FText GetGuess()
{
    int32 CurrentTry = BCGame.GetCurrentTry();
    FText Guess = "";

    std::cout << "Try " << CurrentTry << ". Enter your guess: ";
    getline(std::cin, Guess);
    return Guess;
}


// Welcome
void GameIntro()
{
    std::cout << "Welcome to Bulls and Cows, a fun game." << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram i'm thinking of?" << std::endl;
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();

    int32 MaxTries = BCGame.GetMaxTries();

    for (int32 count = 1; count <= MaxTries; count++)
    {
        FText Guess = GetGuess();

        EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << " Cows = " << BullCowCount.Cows << std::endl;
    }
}

bool PlayAgain()
{
    std::cout << "Do you want to play again? Y/N?" << std::endl;
    FText Choice = "";
    getline(std:: cin, Choice);



    std::cout << "Player choice: " << (Choice[0] == 'y');
    std::cout << std::endl;

    if (Choice[0] == 'y' || Choice[0] == 'Y')
        std::cout << "Restarting the game..." << std::endl;
    else
        std::cout << "Player choiced finish the game" << std::endl;

    return (Choice[0] == 'y' || (Choice[0] == 'Y'));
}
