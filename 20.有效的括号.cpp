/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        map<char, char> myMap{
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> myStack;
        for (char ch : s) {
            if (myMap.count(ch)) {
                if (myStack.empty() || myMap[ch] != myStack.top()) {
                    return false;
                }
                myStack.pop();
            } else {
                myStack.push(ch);
            }
        }
        return myStack.empty();
    }
};
// @lc code=end

