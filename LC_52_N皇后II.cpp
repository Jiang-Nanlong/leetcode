#include <iostream>
#include <vector>
#include <string>
using namespace std;

//�����Ҫͳ������Ҫ������̵�����

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

    // �ڶ�����
    int res;
    int totalNQueens1(int n) {
        res = 0;
        string s(n, '.');
        vector<string> chessboard(n, s);
        backtracking1(chessboard, 0);
        return res;
    }

    void backtracking1(vector<string>& chessboard, int row) {
        if (row == chessboard.size()) {
            res++;
            return;
        }

        for (int i = 0; i < chessboard.size(); i++) {
            if (isValid1(chessboard, row, i)) {
                chessboard[row][i] = 'Q';
                backtracking1(chessboard, row + 1);
                chessboard[row][i] = '.';
            }
        }
    }

    bool isValid1(vector<string>& chessboard, int row, int col) {
        for (int i = 0; i < row; i++)
            if (chessboard[i][col] == 'Q')
                return false;

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (chessboard[i][j] == 'Q')
                return false;

        for (int i = row - 1, j = col + 1; i >= 0 && j < chessboard.size();
            i--, j++)
            if (chessboard[i][j] == 'Q')
                return false;

        return true;
    }
};

int main() {
    Solution st;
    cout << st.totalNQueens(4) << endl;
    cout << st.totalNQueens1(4) << endl;
    return 0;
}