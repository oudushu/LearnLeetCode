/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        int index1 = n1 - 1, index2 = n2 - 1, upper = 0;
        string res = "";
        while (index1 >= 0 || index2 >= 0 || upper != 0) {
            int r1 = index1 >= 0 ? num1[index1] - '0' : 0;
            int r2 = index2 >= 0 ? num2[index2] - '0' : 0;
            int result = r1 + r2 + upper;
            res.push_back('0' + result % 10);
            upper = result / 10;
            -- index1;
            -- index2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

