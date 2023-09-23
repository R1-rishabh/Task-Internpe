#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    int playerChoice, computerChoice;

    cout << "Let's play Rock, Paper, Scissors!" << endl;
    cout << "Enter your choice:" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cout << "Your choice (1/2/3): ";
    cin >> playerChoice;

    // Validate player's choice
    if (playerChoice < 1 || playerChoice > 3) {
        cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
        return 1; // Exit with an error code
    }

    // Generate a random choice for the computer (1 for Rock, 2 for Paper, 3 for Scissors)
    computerChoice = rand() % 3 + 1;

    cout << "Computer chose: ";
    switch (computerChoice) {
        case 1:
            cout << "Rock" << endl;
            break;
        case 2:
            cout << "Paper" << endl;
            break;
        case 3:
            cout << "Scissors" << endl;
            break;
    }

    cout << "You chose: ";
    switch (playerChoice) {
        case 1:
            cout << "Rock" << endl;
            break;
        case 2:
            cout << "Paper" << endl;
            break;
        case 3:
            cout << "Scissors" << endl;
            break;
    }

    // Determine the winner
    if (playerChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((playerChoice == 1 && computerChoice == 3) || 
               (playerChoice == 2 && computerChoice == 1) || 
               (playerChoice == 3 && computerChoice == 2)) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }

    return 0;
}
