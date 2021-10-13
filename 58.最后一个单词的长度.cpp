/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int right = s.size() - 1;
        while (right >= 0) {
            if (s[right] != ' ') break;
            right --;
        }
        int left = right;
        while (left >= 0) {
            if (s[left] == ' ') break;
            left --;
        }
        return right - left;
    }
};
// @lc code=end

