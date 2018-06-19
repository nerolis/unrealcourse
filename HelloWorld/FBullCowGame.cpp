#include "FBullCowGame.hpp"
using int32 = int;

FBullCowGame::FBullCowGame()
{
    Reset();

}

int32 FBullCowGame::GetMaxTries() const
{
    return MyMaxTries;

}

int32 FBullCowGame::GetCurrentTry() const
{
    return MyCurrentTry;

}

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;

    const FString HIDDEN_WORD = "toto";
    MyHiddenWord = HIDDEN_WORD;

    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const
{
    return 0;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (Guess != MyHiddenWord)
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (false)
    {
        return EGuessStatus::Not_Lowercase;
    }
    else if (Guess.length() != GetHiddenWordLength())
    {
        return EGuessStatus::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK;
    }
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;

    int32 WordLength = MyHiddenWord.length();

    for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
        for (int32 GChar = 0; GChar < WordLength; GChar++) {
            if (Guess[GChar] == MyHiddenWord[MHWChar]) {
                if (MHWChar == GChar) {
                    BullCowCount.Bulls++;
                }
                else {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    return BullCowCount;
};

int32 FBullCowGame::GetHiddenWordLength() const { 
    return MyHiddenWord.length();
} 








