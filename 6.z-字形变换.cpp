/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> resArr(min(numRows, int(s.size())));
        bool down = false;
        int curRow = 0;
        for (char ch : s) {
            resArr[curRow] += ch;
            if (curRow == 0 || curRow == numRows - 1) {
                down = !down;
            }
            curRow += down ? 1 : -1;
        }
        string res;
        for (string str : resArr) {
            res += str;
        }
        return res;
    }
};
// @lc code=end

