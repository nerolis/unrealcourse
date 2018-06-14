//
//  main.cpp
//  HelloWorld
//
//  Created by logh on 6/13/18.
//  Copyright © 2018 logh. All rights reserved.
//

#include <iostream>

using namespace std;


int main()
{
    constexpr int WORLD_LENGTH = 5;
    
    // Welcome
    cout << "Welcome to Bulls and Cows, a fun game." << endl;
    cout << "Can you guess the " << WORLD_LENGTH;
    cout << "letter isogram i'm thinking of?" << endl;
    cout << endl;
    
    // Player Guess
    cout << "Enter your guess: ";
    string Guess = "";
    cin  >> Guess;
    
    cout << "Your guess was: " << Guess << endl;
    
    cout << endl;
}
