/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        // reverse(a.begin(), a.end());
        // reverse(b.begin(), b.end());
        // string res;
        // int n = max(a.size(), b.size()), carry = 0;
        // for (int i = 0; i < n; i ++) {
        //     if (i < a.size()) {
        //         carry += a[i] - '0';
        //     }
        //     if (i < b.size()) {
        //         carry += b[i] - '0';
        //     }
        //     res.push_back(carry % 2 == 0 ? '0' : '1');
        //     carry /= 2;
        // }
        // if (carry > 0) {
        //     res.push_back('1');
        // }
        // reverse(res.begin(), res.end());
        // return res;

        int index1 = a.size() - 1, index2 = b.size() - 1, carry = 0;
        string res;
        while (index1 >= 0 || index2 >= 0 || carry > 0) {
            int r1 = index1 >= 0 ? a[index1 --] - '0' : 0;
            int r2 = index2 >= 0 ? b[index2 --] - '0' : 0;
            int val = r1 + r2 + carry;
            res += to_string(val % 2);
            carry = val / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

