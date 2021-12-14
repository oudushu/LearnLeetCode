/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        auto matrix_new = matrix;
        for (int i = 0; i < size; ++ i) {
            for (int j = 0; j < size; ++ j) {
                matrix_new[j][size - i - 1] = matrix[i][j];
            }
        }
        matrix = matrix_new;
    }
};
// @lc code=end

