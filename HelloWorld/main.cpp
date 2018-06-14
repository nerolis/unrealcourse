//
//  main.cpp
//  HelloWorld
//
//  Created by logh on 6/13/18.
//  Copyright © 2018 logh. All rights reserved.
//

#include <iostream>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

int main()
{
    
    PrintIntro();
    
    GetGuessAndPrintBack();
    GetGuessAndPrintBack();
    
    cout << endl;
}

// Get a Guess from the Player
string GetGuessAndPrintBack()
{
    cout << "Enter your guess: ";
    string Guess = "";
    getline(cin, Guess);
    
    // Print the Guess back to Player
    cout << "Your guess was: " << Guess << endl;
    
    return Guess;
}

// Welcome
void PrintIntro()
{
    constexpr int WORLD_LENGTH = 5;
    cout << "Welcome to Bulls and Cows, a fun game." << endl;
    cout << "Can you guess the " << WORLD_LENGTH;
    cout << "letter isogram i'm thinking of?" << endl;
    cout << endl;
    return;
}

