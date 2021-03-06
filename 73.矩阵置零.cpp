/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> rowArr(row, 0);
        vector<int> colArr(col, 0);
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                if (matrix[i][j] == 0) {
                    rowArr[i] = 1;
                    colArr[j] = 1;
                }
            }
        }
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                if (rowArr[i] == 1 || colArr[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
// @lc code=end

