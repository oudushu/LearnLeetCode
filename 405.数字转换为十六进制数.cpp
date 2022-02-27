/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string res;
        uint32_t n = num;
        while (n) {
            int val = n % 16;
            if (val < 10) {
                res += to_string(val);
            } else {
                res += (val - 10 + 'a');
            }
            n /= 16;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

