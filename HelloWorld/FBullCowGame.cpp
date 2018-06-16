#include "FBullCowGame.hpp"
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;

    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;

    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const
{
    return 0;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
    return 0;
}

// Receives a VALID guess, increments and returns count;
BullCowCount FBullCowGame::SubmitGuess(FString)
{
    MyCurrentTry++;
    BullCowCount BullCowCount;

    return BullCowCount;
};







