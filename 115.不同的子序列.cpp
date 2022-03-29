/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return 0;
        vector<vector<uint64_t>> dp(m + 1, vector<uint64_t>(n + 1));
        for (int i = 0; i <= m; ++i) {
            dp[i][n] = 1;
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

