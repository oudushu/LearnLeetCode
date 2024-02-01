/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int maxVal = 0;
//         int minVal = INT_MAX;
//         for (int i = 0; i < prices.size(); ++ i) {
//             minVal = min(minVal, prices[i]);
//             maxVal = max(maxVal, prices[i] - minVal);
//         }
//         return maxVal;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0) return 0;
        vector<int> dp(size, 0);
        int minPrice = prices[0];
        for (int i = 1; i < size; ++i) {
            minPrice = min(minPrice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
        }
        return dp[size - 1];
    }
};
// @lc code=end

