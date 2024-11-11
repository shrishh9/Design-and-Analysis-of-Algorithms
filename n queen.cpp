#include <iostream>
#include <vector>
using namespace std;

// Function to check if a position is safe for placing a queen
bool isSafe(const vector<string>& board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueens(vector<string>& board, int row, int n) {
    if (row == n) {
        // All queens are placed, print the board
        for (const string& row : board) {
            cout << row << endl;
        }
        cout << endl;
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            // Place the queen
            board[row][col] = 'Q';

            // Recur to place the next queen
            if (solveNQueens(board, row + 1, n))
                return true;

            // Backtrack and remove the queen
            board[row][col] = '.';
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    // Initialize the chessboard
    vector<string> board(n, string(n, '.'));

    if (!solveNQueens(board, 0, n)) {
        cout << "No solution exists for " << n << " queens." << endl;
    }

    return 0;
}
