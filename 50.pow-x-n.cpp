/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
private:
    double quickMul(double x, long long n) {
        double res = 1.0;
        double mul = x;
        while (n > 0) {
            if (n % 2 == 1) {
                res *= mul;
            }
            mul *= mul;
            n /= 2;
        }
        return res;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1 / quickMul(x, -N);
    }
};
// @lc code=end

