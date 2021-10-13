/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxVal = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (i <= maxVal) {
                maxVal = max(maxVal, nums[i] + i);
                if (maxVal >= nums.size() - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

