/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dpMax(nums), dpMin(nums);
        for (int i = 1; i < nums.size(); ++ i) {
            dpMax[i] = max(dpMax[i - 1] * nums[i], max(dpMin[i - 1] * nums[i], nums[i]));
            dpMin[i] = min(dpMin[i - 1] * nums[i], min(dpMax[i - 1] * nums[i], nums[i]));
        }
        return *max_element(dpMax.begin(), dpMax.end());

        // int maxF = nums[0], minF = nums[0], ans = nums[0];
        // for (int i = 1; i < nums.size(); ++ i) {
        //     int mx = maxF, mn = minF;
        //     maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
        //     minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
        //     ans = max(maxF, ans);
        // }
        // return ans;
    }
};
// @lc code=end

