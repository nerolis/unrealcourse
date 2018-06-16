#include <string>
using int32 = int;
using FString = std::string;

struct BullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame {
public:
    FBullCowGame(); // Constructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;

    void Reset();
    bool CheckGuessValidity(FString);

    BullCowCount SubmitGuess(FString);

private:
    // Init in constructor;
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};
