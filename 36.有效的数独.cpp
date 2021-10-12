/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector(9, 0));
        vector<vector<int>> col(9, vector(9, 0));
        vector<vector<int>> mat(9, vector(9, 0));
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    int index = board[i][j] - '1';
                    int m = i / 3 * 3 + j / 3;
                    if (row[i][index] == 0 && col[j][index] == 0 && mat[m][index] == 0) {
                        row[i][index] = 1;
                        col[j][index] = 1;
                        mat[m][index] = 1;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

