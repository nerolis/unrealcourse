#include <string>

class FBullCowGame {
public:
    FBullCowGame(); // Constructor

    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;

    void Reset();
    bool CheckGuessValidity(std::string);

private:
    // Init in constructor;
    int MyCurrentTry;
    int MyMaxTries;
    bool IsIsogram();
};
