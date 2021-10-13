/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxVal = dp[0];
        for (int i = 1; i < nums.size(); i ++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
};
// @lc code=end

