/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
private:
    pair<int, int> palindrome(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left --;
            right ++;
        }
        return {left + 1, right - 1};
    }
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i ++) {
            auto [x1, y1] = palindrome(s, i, i);
            auto [x2, y2] = palindrome(s, i, i + 1);
            if (y1 - x1 > right - left) {
                left = x1;
                right = y1;
            }
            if (y2 - x2 > right - left) {
                left = x2;
                right = y2;
            }
        }
        return s.substr(left, right - left + 1);
    }
};
// @lc code=end

