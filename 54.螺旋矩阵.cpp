/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        if (row == 0 || col == 0) {
            return {};
        }
        int left = 0, right = col - 1, up = 0, down = row - 1;
        vector<int> res;

        while (left <= right && up <= down) {
            for (int c = left; c <= right; ++ c) {
                res.push_back(matrix[up][c]);
            }
            
            for (int r = up + 1; r <= down; ++ r) {
                res.push_back(matrix[r][right]);
            }

            if (left < right && up < down) {
                for (int c = right - 1; c > left; -- c) {
                    res.push_back(matrix[down][c]);
                }

                for (int r = down; r > up; -- r) {
                    res.push_back(matrix[r][left]);
                }
            }
            ++ up;
            -- right;
            -- down;
            ++ left;
        }
        return res;
    }
};
// @lc code=end

