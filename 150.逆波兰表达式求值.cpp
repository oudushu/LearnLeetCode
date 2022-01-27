/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
private:
    bool isNum(string &str) {
        return !(str == "+" || str == "-" || str == "*" || str == "/");
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> myStack;
        for (int i = 0; i < tokens.size(); ++ i) {
            string &str = tokens[i];
            if (isNum(str)) {
                myStack.push(atoi(str.c_str()));
            } else {
                int num2 = myStack.top();
                myStack.pop();
                int num1 = myStack.top();
                myStack.pop();
                switch (str[0]) {
                    case '+': myStack.push(num1 + num2); break;
                    case '-': myStack.push(num1 - num2); break;
                    case '*': myStack.push(num1 * num2); break;
                    case '/': myStack.push(num1 / num2); break;
                }
            }
        }
        return myStack.top();
    }
};
// @lc code=end

