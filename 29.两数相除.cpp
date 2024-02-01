/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long dividendLong = abs((long)dividend);
        long divisorLong = abs((long)divisor);
        long res = 0;
        while (dividendLong >= divisorLong) {
            long tmp = divisorLong, i = 1;
            while (dividendLong >= tmp) {
                dividendLong -= tmp;
                res += i;
                tmp <<= 1;
                i <<= 1;
            }
        }
        res *= sign;
        if (res > INT_MAX || res < INT_MIN) {
            return INT_MAX;
        }
        return res;
    }
};
// @lc code=end

