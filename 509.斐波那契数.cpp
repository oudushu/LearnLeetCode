/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int pre = 0, cur = 1;
        for (int i = 2; i <= n; ++ i) {
            int sum = pre + cur;
            pre = cur;
            cur = sum;
        }
        return cur;
    }
};
// @lc code=end

