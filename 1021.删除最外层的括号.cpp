/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> myStack;
        string res;
        for (int i = 0; i < s.size(); ++ i) {
            if (s[i] == '(') {
                if (!myStack.empty()) {
                    res += s[i];
                }
                myStack.push(i);
            } else {
                myStack.pop();
                if (!myStack.empty()) {
                    res += s[i];
                }
            }
        }
        return res;
    }
};
// @lc code=end

