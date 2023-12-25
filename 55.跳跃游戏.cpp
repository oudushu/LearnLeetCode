/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int maxVal = 0;
//         for (int i = 0; i < nums.size(); i ++) {
//             if (i <= maxVal) {
//                 maxVal = max(maxVal, nums[i] + i);
//                 if (maxVal >= nums.size() - 1) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (k < i) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end

