/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int left = 0, right = 0, sum = 0, res = INT_MAX;
        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                res = min(res, right - left + 1);
                sum -= nums[left];
                ++ left;
            }
            ++ right;
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end

