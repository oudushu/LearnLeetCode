/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        if (path.size() == 0) return "";
        vector<string> myStack;
        int i = 0, n = path.size();
        string tempStr;
        while (i < n) {
            if (path[i] == '/') {
                ++ i;
            } else {
                while (i < n && path[i] != '/') {
                    tempStr += path[i];
                    ++ i;
                }
                if (tempStr == ".") {

                } else if (tempStr == "..") {
                    if (!myStack.empty()) {
                        myStack.pop_back();
                    }
                } else {
                    myStack.push_back(tempStr);
                }
                tempStr = "";
            }
        }
        if (myStack.empty()) {
            return "/";
        }
        string res;
        for (string str : myStack) {
            res += ('/' + str);
        }
        return res;
    }
};
// @lc code=end

