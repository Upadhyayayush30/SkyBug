#include <iostream>
#include <cstdlib>  // For rand() and srand() functions
#include <ctime>    // For time() function

using namespace std;

int main() {
    // Seed the random number generator with current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Try to guess the number between 1 and 100." << endl;

    do {
        // Get user's guess
        cout << "Enter your guess: ";
        cin >> userGuess;

        // Increment attempts
        attempts++;

        // Provide feedback on the guess
        if (userGuess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }

    } while (userGuess != secretNumber);

    return 0;
}
