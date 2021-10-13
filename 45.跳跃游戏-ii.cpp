/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxVal = 0, step = 0, end = 0;
        for (int i = 0; i < nums.size() - 1; i ++) {
            if (maxVal >= i) {
                maxVal = max(maxVal, nums[i] + i);
                if (end == i) {
                    end = maxVal;
                    step ++;
                }
            }
        }
        return step;
    }
};
// @lc code=end

