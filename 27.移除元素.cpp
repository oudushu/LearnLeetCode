/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len == 0) return 0;
        int index = 0;
        for (int i = 0; i < len; i ++) {
            if (nums[i] != val) {
                nums[index] = nums[i];
                index ++;
            }
        }
        return index;
    }
};
// @lc code=end

