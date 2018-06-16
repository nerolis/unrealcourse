#include <string>
using int32 = int;
using FString = std::string;

class FBullCowGame {
public:
    FBullCowGame(); // Constructor

    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;

    void Reset();
    bool CheckGuessValidity(FString);

private:
    // Init in constructor;
    int32 MyCurrentTry;
    int32 MyMaxTries;
    bool IsIsogram();
};
