/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int left = 0, prod = 1, res = 0;
        for (int right = 0; right < nums.size(); ++ right) {
            prod *= nums[right];
            while (prod >= k) {
                prod /= nums[left];
                ++ left;
            }
            res += right - left + 1;
        }
        return res;
    }
};
// @lc code=end

