/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int left = 0, right = 0, res = 0;
        int n = s.size();
        while (left <= right && right < n) {
            while (left < n && s[left] == ' ') {
                ++ left;
            }
            right = left;
            while (right < n && s[right] != ' ') {
                ++ right;
            }
            if (right - left > 0) {
                ++ res;
            }
            left = right;
        }
        return res;
    }
};
// @lc code=end

