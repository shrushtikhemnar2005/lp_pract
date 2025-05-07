#include <iostream>
using namespace std;

#define N 4  // Size of the board, 4x4 in this case

// Function to print the board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {  // Loop over each row
        for (int j = 0; j < N; j++) {  // Loop over each column
            cout << (board[i][j] ? "Q " : ". ");  
        }
        cout << endl;  // Move to next line after printing a row
    }
    cout << "\n";  // Print an extra line for better readability
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check left side in the same row
    for (int i = 0; i < col; i++)  
        if (board[row][i]) return false;

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)  
        if (board[i][j]) return false;

    // Check lower-left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--)  
        if (board[i][j]) return false;

    return true; // If no conflicts, the position is safe
}

// Function to solve N-Queens using backtracking
bool solveNQueens(int board[N][N], int col) {
    if (col >= N) {  // If all queens are placed
        printBoard(board);  // Print solution
        return true;  // Return true (solution found)
    }

    bool foundSolution=false;//Initially empty set false

    for (int i = 0; i < N; i++) { // Try placing queen in each row of current column
        if (isSafe(board, i, col)) {  // Check if position (i, col) is safe
            board[i][col] = 1; // Place the queen
            foundSolution = solveNQueens(board, col + 1) || foundSolution; // Recursive call
            board[i][col] = 0; // Backtrack (remove the queen)
        }
    }
    return foundSolution; // Return true if at least one solution was found
}

// Function to initialize the board and start solving
void solve() {
    int board[N][N] = {0};
  //CALLING solveNQueens() placing Q at 0 th col

    if (!solveNQueens(board, 0))  // If no solution exists
        cout << "No solution exists" << endl;
}

// Main function
int main() {
    solve(); // Call solve function
    return 0;
}
