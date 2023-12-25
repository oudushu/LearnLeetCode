/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int maxVal = 0, step = 0, end = 0;
//         for (int i = 0; i < nums.size() - 1; i ++) {
//             if (maxVal >= i) {
//                 maxVal = max(maxVal, nums[i] + i);
//                 if (end == i) {
//                     end = maxVal;
//                     step ++;
//                 }
//             }
//         }
//         return step;
//     }
// };

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, begin = 0, end = 0;
        while (end < nums.size() - 1) {
            int maxPos = 0;
            for (int i = begin; i <= end; ++i) {
                maxPos = max(maxPos, i + nums[i]);
            }
            begin = end + 1;
            end = maxPos;
            ++ans;
        }
        return ans;
    }
};

// @lc code=end

