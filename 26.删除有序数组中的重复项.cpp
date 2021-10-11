/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int slow = 1;
        for (int i = 1; i < size; i ++) {
            if (nums[i] != nums[i - 1]) {
                nums[slow] = nums[i];
                slow ++;
            }
        }
        return slow;
    }
};
// @lc code=end

