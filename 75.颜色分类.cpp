/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int slow = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                swap(nums[slow], nums[i]);
                ++slow;
            }
        }
        for (int i = slow; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                swap(nums[slow], nums[i]);
                ++slow;
            }
        }
    }
};
// @lc code=end

