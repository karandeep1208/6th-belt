#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); // Initialize board with '.'

        solve(0, ans, board, n);
        return ans;
    }

private:
    bool isSafe(int row, int col, vector<string> &board, int n) {
        int x = row, y = col;

        // Check left row
        while (y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            y--;
        }

        // Check upper diagonal
        x = row, y = col;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            y--;
            x--;
        }

        // Check lower diagonal
        x = row, y = col;
        while (x < n && y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            y--;
            x++;
        }

        return true;
    }

    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n) {
        // base case
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                board[row][col] = '.'; // Backtrack
            }
        }
    }
};

// Function to print solutions in a readable format
void printSolutions(vector<vector<string>> &solutions) {
    int count = 1;
    for (auto &sol : solutions) {
        cout << "Solution " << count++ << ":\n";
        for (const string &row : sol) {
            cout << row << endl;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of N for the N-Queens problem: ";
    cin >> n;

    Solution sol;
    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "Total Solutions: " << solutions.size() << endl;
    printSolutions(solutions);

    return 0;
}