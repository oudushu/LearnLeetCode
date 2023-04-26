/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
private:
    int robRange(vector<int>& nums, int start, int end) {
        vector<int> dp(end - start + 1, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; ++i) {
            int index = i - start;
            dp[index] = max(dp[index - 1], dp[index - 2] + nums[i]);
        }
        return dp[end - start];
    }
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        } else if (size == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, size - 2), robRange(nums, 1, size - 1));
    }
};
// @lc code=end

