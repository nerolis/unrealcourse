#include <iostream>

using namespace std;

// Func Proto
void GameIntro();
void PlayGame();
string GetGuess();
bool PlayAgain();

int main()
{
    do {
        GameIntro();
        PlayGame();
    }
    while (PlayAgain());

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
void GameIntro()
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

bool PlayAgain()
{
    cout << "Do you want to play again? Y/N?" << endl;
    string Choice = "";
    getline(cin, Choice);



    cout << "Player choice: " << (Choice[0] == 'y');
    cout << endl;

    if (Choice[0] == 'y' || Choice[0] == 'Y')
        cout << "Restarting the game..." << endl;
    else
        cout << "Player choiced finish the game" << endl;

    return (Choice[0] == 'y' || (Choice[0] == 'Y'));
}
