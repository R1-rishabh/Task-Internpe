#include <iostream>
#include <vector>

using namespace std;

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    for (const vector<char>& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;  // Horizontal win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;  // Vertical win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;  // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;  // Diagonal win (top-right to bottom-left)
    }
    return false;
}

// Function to check if the game is a tie
bool checkTie(const vector<vector<char>>& board) {
    for (const vector<char>& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;  // There is an empty cell, game is not a tie
            }
        }
    }
    return true;  // All cells are filled, game is a tie
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));  // Initialize an empty 3x3 board
    char currentPlayer = 'X';  // Player X starts

    int row, col;

    cout << "Welcome to TIC TAC TOE!" << endl;

    while (true) {
        displayBoard(board);

        // Get the player's move
        cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update the board
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            break;
        }

        // Check if the game is a tie
        if (checkTie(board)) {
            displayBoard(board);
            cout << "It's a tie! The game is over." << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
