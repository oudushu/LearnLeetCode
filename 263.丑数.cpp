/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        vector<int> nums = {2, 3, 5};
        for (int num : nums) {
            while (n % num == 0) {
                n /= num;
            }
        }
        return n == 1;
    }
};
// @lc code=end

