#include <string>
using int32 = int;
using FString = std::string;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum EGuessStatus
{
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};


class FBullCowGame {
public:
    FBullCowGame(); // Constructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;

    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString Guess) const;

    void Reset();
    
    FBullCowCount SubmitValidGuess(FString Guess);

private:
    // Init in constructor;
    bool IsIsogram(FString Word) const;
    bool IsLowercase(FString Word) const;
    bool bGameIsWon;

    int32 MyCurrentTry;
    FString MyHiddenWord;
};
