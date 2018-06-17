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

bool FBullCowGame::CheckGuessValidity(std::string) const
{
    return 0;
}

// Receives a VALID guess, increments and returns count;
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;

    int32 HiddenWordLength = MyHiddenWord.length();

    for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
        for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
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








