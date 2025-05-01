#include <vector>
#include <string>

class Solution {
public:
    bool isSafe1(int row, int col, std::vector<std::string>& board, int n) {
        // Checking upper diagonal
        int duprow = row;
        int dupcol = col;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        col = dupcol;
        row = duprow;
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        while (row < n && col >= 0) { // Use && instead of &
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }

    void solve(int col, std::vector<std::string>& board, std::vector<std::vector<std::string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe1(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.'; // Backtrack
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> board(n, std::string(n, '.')); // Create an n x n board initialized with '.'

        solve(0, board, ans, n);
        return ans;
    }
};