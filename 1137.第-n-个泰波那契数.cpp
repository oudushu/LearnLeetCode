/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        int x = 0, y = 1, z = 1;
        for (int i = 3; i <= n; ++ i) {
            int sum = x + y + z;
            x = y;
            y = z;
            z = sum;
        }
        return z;
    }
};
// @lc code=end

