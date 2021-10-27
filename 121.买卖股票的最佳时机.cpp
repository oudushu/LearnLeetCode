/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxVal = 0;
        int minVal = INT_MAX;
        for (int i = 0; i < prices.size(); ++ i) {
            minVal = min(minVal, prices[i]);
            maxVal = max(maxVal, prices[i] - minVal);
        }
        return maxVal;
    }
};
// @lc code=end

