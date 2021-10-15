/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res;
        int n = max(a.size(), b.size()), carry = 0;
        for (int i = 0; i < n; i ++) {
            if (i < a.size()) {
                carry += a[i] - '0';
            }
            if (i < b.size()) {
                carry += b[i] - '0';
            }
            res.push_back(carry % 2 == 0 ? '0' : '1');
            carry /= 2;
        }
        if (carry > 0) {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

