#include "FBullCowGame.hpp"

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset() { 
    return;
}

bool FBullCowGame::IsGameWon() const {
    return 0;
}

bool FBullCowGame::CheckGuessValidity(std::string) { 
    return 0;
}




