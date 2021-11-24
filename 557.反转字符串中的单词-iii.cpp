/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
private:
    void reverse(string &s, int left, int right) {
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left ++;
            right --;
        }
    }
public:
    string reverseWords(string s) {
        int left = 0, right = 0;
        int size = s.size();
        while (left < size && right < size) {
            while (left < size && s[left] == ' ') {
                left ++;
            }
            right = left;
            while (right < size && s[right] != ' ') {
                right ++;
            }
            reverse(s, left, right - 1);
            left = right;
        }
        return s;
    }
};
// @lc code=end

