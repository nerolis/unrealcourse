#include <iostream>

using namespace std;

// Func Proto
void PrintIntro();
void PlayGame();
string GetGuess();

int main()
{
    PrintIntro();
    PlayGame();
    // Yes, actually it's not necessary in 2018 compilers;
    return 0;
}

// Get a Guess from the Player
string GetGuess()
{
    cout << "Enter your guess: ";
    string Guess = "";
    getline(cin, Guess);
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

void PlayGame()
{
    constexpr int NUMBER_OF_TURNS = 5;
    for (int count = 1; count <= NUMBER_OF_TURNS; count++)
    {
        string Guess = GetGuess();
        cout << "Your guess was: " << Guess << endl;
        cout << endl;
    }
}
