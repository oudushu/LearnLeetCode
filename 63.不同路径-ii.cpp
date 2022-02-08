/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        // vector<int> dp(col, 0);
        // dp[0] = (obstacleGrid[0][0] == 0);
        // for (int i = 0; i < row; ++ i) {
        //     for (int j = 0; j < col; ++ j) {
        //         if (obstacleGrid[i][j] == 1) {
        //             dp[j] = 0;
        //             continue;
        //         }
        //         if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
        //             dp[j] += dp[j - 1];
        //         }
        //     }
        // }
        // return dp.back();

        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        // 第一行
        for (int i = 0; i < col; ++ i) {
            if (obstacleGrid[0][i] == 1) {
                break;
            }
            dp[0][i] = 1;
        }
        // 第一列
        for (int i = 0; i < row; ++ i) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i][0] = 1;
        }
        for (int i = 0; i < row; ++ i) {
            for (int j = 0; j < col; ++ j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if (i > 0 && j > 0) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[row - 1][col - 1];
    }
};
// @lc code=end

