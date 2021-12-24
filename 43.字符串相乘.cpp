/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
private:
    string sumOfString(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size(), upper = 0;
        int index1 = n1 - 1, index2 = n2 - 1;
        string res;
        while (index1 >= 0 || index2 >= 0 || upper != 0) {
            int r1 = index1 >= 0 ? num1[index1] - '0' : 0;
            int r2 = index2 >= 0 ? num2[index2] - '0' : 0;
            int sum = r1 + r2 + upper;
            res.push_back('0' + sum % 10);
            upper = sum / 10;
            -- index1;
            -- index2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string multiplyOfString(string num1, char num2) {
        int index = num1.size() - 1, upper = 0;
        int n2 = num2 - '0';
        string res;
        while (index >= 0 || upper != 0) {
            int r = index >= 0 ? num1[index] - '0' : 0;
            int mul = r * n2 + upper;
            res.push_back('0' + mul % 10);
            upper = mul / 10;
            -- index;
        }
        reverse(res.begin(), res.end());
        return res;
    }

public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        string res;
        int n1 = num1.size(), n2 = num2.size();
        for (int i = n2 - 1; i >= 0; -- i) {
            string mul = multiplyOfString(num1, num2[i]);

            int countOfZero = n2 - 1 - i;
            while (countOfZero > 0) {
                mul.push_back('0');
                -- countOfZero;
            }

            res = sumOfString(res, mul);
        }
        return res;
    }
};
// @lc code=end

