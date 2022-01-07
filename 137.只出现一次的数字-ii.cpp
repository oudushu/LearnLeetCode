/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++ i) {
            int total = 0;
            for (int num : nums) {
                total += ((num >> i) & 1);
            }
            if (total % 3) {
                res |= (1 << i);
            }
        }
        return res;
    }
};
// @lc code=end

