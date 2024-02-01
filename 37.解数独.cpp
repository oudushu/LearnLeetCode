/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
private:
    bool valid = false;
    void dfs(vector<vector<char>>& board, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& mat, vector<pair<int, int>>& space, int index) {
        if (index == space.size()) {
            valid = true;
            return;
        }

        auto [r, c] = space[index];
        for (int i = 0; i < 9 && !valid; ++i) {
            int m = r / 3 * 3 + c / 3;
            if (row[r][i] == 0 && col[c][i] == 0 && mat[m][i] == 0) {
                row[r][i] = col[c][i] = mat[m][i] = 1;
                board[r][c] = i + '1';
                dfs(board, row, col, mat, space, index + 1);
                if (!valid) {
                    board[r][c] = '.';
                }
                row[r][i] = col[c][i] = mat[m][i] = 0;
            }
        }
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> mat(9, vector<int>(9, 0));
        vector<pair<int, int>> space;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    space.emplace_back(i, j);
                } else {
                    int m = i / 3 * 3 + j / 3;
                    int val = board[i][j] - '1';
                    row[i][val] = col[j][val] = mat[m][val] = 1;
                }
            }
        }
        dfs(board, row, col, mat, space, 0);
    }
};
// @lc code=end

