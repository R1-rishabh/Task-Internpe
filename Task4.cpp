#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

vector<vector<char>> board(ROWS, vector<char>(COLS, ' '));

bool isWin(char player);
bool isDraw();
void printBoard();
bool dropPiece(int col, char player);

int main() {
    char currentPlayer = 'X';
    int moves = 0;

    while (true) {
        printBoard();

        // Get the column where the current player wants to drop a piece
        int col;
        cout << "Player " << currentPlayer << ", choose a column (1-7): ";
        cin >> col;

        if (col < 1 || col > COLS) {
            cout << "Invalid input. Please choose a column between 1 and 7." << endl;
            continue;
        }

        if (dropPiece(col - 1, currentPlayer)) {
            moves++;
            if (isWin(currentPlayer)) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            } else if (isDraw()) {
                printBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Column " << col << " is full. Try again." << endl;
        }
    }

    return 0;
}

bool isWin(char player) {
    // Check for horizontal, vertical, and diagonal wins
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (col + 3 < COLS &&
                board[row][col] == player &&
                board[row][col + 1] == player &&
                board[row][col + 2] == player &&
                board[row][col + 3] == player) {
                return true;
            }
            if (row + 3 < ROWS) {
                if (board[row][col] == player &&
                    board[row + 1][col] == player &&
                    board[row + 2][col] == player &&
                    board[row + 3][col] == player) {
                    return true;
                }
                if (col + 3 < COLS &&
                    board[row][col] == player &&
                    board[row + 1][col + 1] == player &&
                    board[row + 2][col + 2] == player &&
                    board[row + 3][col + 3] == player) {
                    return true;
                }
                if (col - 3 >= 0 &&
                    board[row][col] == player &&
                    board[row + 1][col - 1] == player &&
                    board[row + 2][col - 2] == player &&
                    board[row + 3][col - 3] == player) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isDraw() {
    int moves;
    return moves == ROWS * COLS;
}

void printBoard() {
    system("clear"); // Use "cls" instead of "clear" on Windows
    cout << "Connect Four" << endl;
    cout << "  1   2   3   4   5   6   7" << endl;

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            cout << "| " << board[row][col] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-----------------------------" << endl;
}

bool dropPiece(int col, char player) {
    for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == ' ') {
            board[row][col] = player;
            return true;
        }
    }
    return false;
}
