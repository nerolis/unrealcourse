	//
//  FBullCowGame.cpp
//  HelloWorld
//
//  Created by logh on 6/15/18.
//  Copyright © 2018 logh. All rights reserved.
//

#include "FBullCowGame.hpp"

class FBullCowGame {
public:
    void Reset();
    int GetMaxTries();
    int GetCurrentTry;
    bool IsGameWon();
    bool CheckGuessValidity();

private:
    int MyCurrentTry;
    int MyMaxTries;
    bool IsIsogram();
};
