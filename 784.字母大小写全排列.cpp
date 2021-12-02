/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
private:
    void trackback(string &s, vector<string> &res, int index) {
        if (index == s.size()) {
            res.push_back(s);
            return;
        }
        if (s[index] >= 'A' && s[index] <= 'Z') {
            s[index] = s[index] + ('a' - 'A');
            trackback(s, res, index + 1);
            s[index] = s[index] - ('a' - 'A');
        } else if (s[index] >= 'a' && s[index] <= 'z') {
            s[index] = s[index] - ('a' - 'A');
            trackback(s, res, index + 1);
            s[index] = s[index] + ('a' - 'A');
        }
        trackback(s, res, index + 1);
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        trackback(s, res, 0);
        return res;
    }
};
// @lc code=end

