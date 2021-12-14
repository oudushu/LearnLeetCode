/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int left = s.size() - 1, right = s.size() - 1;
        while (left >= 0 && right >= 0) {

            while (right >= 0 && s[right] == ' ') {
                right --;
            }

            if (right < 0) break;

            left = right;

            while (left >= 0 && s[left] != ' ') {
                left --;
            }
            
            res = res + s.substr(left + 1, right - left) + ' ';

            right = left;
        }

        if (res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};
// @lc code=end

