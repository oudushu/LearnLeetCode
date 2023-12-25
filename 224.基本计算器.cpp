/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> opt;
        opt.push(1);
        int res = 0;
        int i = 0;
        int sign = 1;
        int n = s.size();
        while (i < n) {
            char ch = s[i];
            if (ch == ' ') {
                ++i;
            } else if (ch == '+') {
                sign = opt.top();
                ++i;
            } else if (ch == '-') {
                sign = -opt.top();
                ++i;
            } else if (ch == '(') {
                opt.push(sign);
                ++i;
            } else if (ch == ')') {
                opt.pop();
                ++i;
            } else {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                res += sign * num;
            }
        }
        return res;
    }
};
// @lc code=end

