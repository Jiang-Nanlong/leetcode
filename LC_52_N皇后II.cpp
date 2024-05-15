#include <iostream>
#include <vector>
#include <string>
using namespace std;

//这次是要统计满足要求的棋盘的数量

class Solution {
public:
    int num;
    int totalNQueens(int n) {
        string s(n, '.');
        vector<string> board(n, s);
        num = 0;
        backtrace(board, 0, n);
        return num;
    }

    void backtrace(vector<string>& board, int row, int n) {
        if (row == n) {
            num++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                backtrace(board, row + 1, n);
                board[row][col] = '.';
            }
        }
    }

    bool isValid(vector<string>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size();
            i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};

int main() {
    Solution st;
    cout << st.totalNQueens(4) << endl;
    return 0;
}