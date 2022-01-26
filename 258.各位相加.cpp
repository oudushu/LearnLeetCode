/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        int n = num;
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return addDigits(res);
    }
};
// @lc code=end

