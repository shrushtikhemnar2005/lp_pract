#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class NQueens_Backtracking {
private:
    int size;
    vector<vector<bool>> board;
    int count;

public:
    NQueens_Backtracking() {
        cout << "Enter size of chessboard: ";
        cin >> size;
        board = vector<vector<bool>>(size, vector<bool>(size, false));
        count = 0;
    }
    
    // Function to print the current board
    void printBoard() {
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                if (board[row][col]) 
                    cout << "Q ";
                else 
                    cout << "X ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Check if it's safe to place a queen at (row, col)
    bool isSafe(int row, int col) {
        // Check column
        for (int i = 0; i < size; i++) {
            if (board[i][col]) return false;
        }

        // Check backward slash (\) diagonal
        int i = row, j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j]) return false;
            i--; j--;
        }

        // Check forward slash (/) diagonal
        i = row, j = col;
        while (i >= 0 && j < size) {
            if (board[i][j]) return false;
            i--; j++;
        }

        return true;
    }

    // Solve the problem using backtracking
    void solve(int row) {
        if (row == size) {
            count++;
            printBoard();
            return;
        }

        for (int col = 0; col < size; col++) {
            if (isSafe(row, col)) {
                board[row][col] = true;
                solve(row + 1);
                board[row][col] = false; // Backtrack
            }
        }
    }

    void startSolving() {
        clock_t start = clock();
        solve(0);
        cout << "Total solutions: " << count << endl;
        cout << "Time taken: " << (double)(clock() - start) / CLOCKS_PER_SEC << " seconds." << endl;
    }
};

int main() {
    NQueens_Backtracking solver;
    solver.startSolving();
    return 0;
}
// Enter size of chessboard: 4
// Q X X X 
// X X Q X 
// X X X Q 
// Q X X X 

// Total solutions: 2
// Time taken: 0.000006 seconds.
