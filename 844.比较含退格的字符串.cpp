/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
private:
    string buildStr(string &s) {
        string str;
        for (char ch : s) {
            if (ch != '#') {
                str.push_back(ch);
            } else if (!str.empty()) {
                str.pop_back();
            }
        }
        return str;
    }
public:
    bool backspaceCompare(string s, string t) {
        return buildStr(s) == buildStr(t);
    }
};
// @lc code=end

