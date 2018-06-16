#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

// Func Proto
void GameIntro();
void PlayGame();
std::string GetGuess();
bool PlayAgain();

FBullCowGame BCGame;

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
std::string GetGuess()
{
    int CurrentTry = BCGame.GetCurrentTry();

    std::cout << "Try " << CurrentTry << ". Enter your guess: ";
    std::string Guess = "";

    getline(std::cin, Guess);
    return Guess;
}


// Welcome
void GameIntro()
{
    constexpr int WORLD_LENGTH = 5;
    std::cout << "Welcome to Bulls and Cows, a fun game." << std::endl;
    std::cout << "Can you guess the " << WORLD_LENGTH;
    std::cout << "letter isogram i'm thinking of?" << std::endl;
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();

    int MaxTries = BCGame.GetMaxTries();

    for (int count = 1; count <= MaxTries; count++)
    {
        std::string Guess = GetGuess();
        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }
}

bool PlayAgain()
{
    std::cout << "Do you want to play again? Y/N?" << std::endl;
    std::string Choice = "";
    getline(std:: cin, Choice);



    std::cout << "Player choice: " << (Choice[0] == 'y');
    std::cout << std::endl;

    if (Choice[0] == 'y' || Choice[0] == 'Y')
        std::cout << "Restarting the game..." << std::endl;
    else
        std::cout << "Player choiced finish the game" << std::endl;

    return (Choice[0] == 'y' || (Choice[0] == 'Y'));
}
