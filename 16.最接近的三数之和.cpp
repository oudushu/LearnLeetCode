/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int best = 1e7;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++ i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                }
                if (abs(sum - target) < abs(best - target)) {
                    best = sum;
                }
                if (sum < target) {
                    int j0 = j;
                    while (j0 < k && nums[j0] == nums[j]) {
                        ++ j0;
                    }
                    j = j0;
                } else {
                    int k0 = k;
                    while (j < k0 && nums[k0] == nums[k]) {
                        -- k0;
                    }
                    k = k0;
                }
            }
        }
        return best;
    }
};
// @lc code=end

