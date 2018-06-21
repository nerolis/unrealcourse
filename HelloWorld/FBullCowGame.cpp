#include "FBullCowGame.hpp"
#include <map>
#define TMap std::map // Unreal standart

using int32 = int;

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
FBullCowGame::FBullCowGame() { Reset(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 3;
    MyMaxTries = MAX_TRIES;

    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    bGameIsWon = false;
    MyCurrentTry = 1;
    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (!isIsogram(Guess))
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
    if (BullCowCount.Bulls == WordLength) {
        bGameIsWon = true;
    } else {
        bGameIsWon = false;
    }
    return BullCowCount;
};


bool FBullCowGame::isIsogram(FString Word) const
{
    if (Word.length() <= 1) {
        return true;
    }

    TMap<char, bool> LetterSeen;
    for (auto Letter : Word) // Для всех букв слова
    {
        Letter = tolower(Letter);
        if (LetterSeen [Letter]) {
            return false; // Не должно быть двух одинаковых букв;
        } else {
            LetterSeen[Letter] = true;
        }
    }

    return true;
}









