/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; ++ i) {
            int maxVal = 0;
            for (int j = 1; j < i; ++ j) {
                maxVal = max(maxVal, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = maxVal;
        }
        return dp[n];
    }
};
// @lc code=end

