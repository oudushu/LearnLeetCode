/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int res = 0;
//         for (int i = 1; i < prices.size(); ++ i) {
//             res += max(0, prices[i] - prices[i - 1]);
//         }
//         return res;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int dp[size][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < size; ++i) {
            // 如果这一天交易完后手里没有股票，那么可能的转移状态为前一天已经没有股票，即 dp[i−1][0]，
            // 或者前一天结束的时候手里持有一支股票，即 dp[i−1][1]，这时候我们要将其卖出，并获得 prices[i] 的收益
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 前一天已经持有一支股票，即 dp[i−1][1]，
            // 或者前一天结束时还没有股票，即 dp[i−1][0]，这时候我们要将其买入，并减少 prices[i] 的收益
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[size - 1][0];
    }
};
// @lc code=end

