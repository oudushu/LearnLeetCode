/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
private:
    int path[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        for (int i = 0; i < 4; ++i) {
            int a = x + path[i][0];
            int b = y + path[i][1];
            dfs(board, a, b);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            dfs(board, i, 0);
            dfs(board, i, col - 1);
        }
        for (int i = 1; i < col - 1; ++i) {
            dfs(board, 0, i);
            dfs(board, row - 1, i);
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end

