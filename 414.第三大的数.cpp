/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<>());
        int diff = 1;
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i] != nums[i - 1] && ++ diff == 3) {
                return nums[i];
            }
        }
        return nums[0];
    }
};
// @lc code=end

