/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        set<char> mySet = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < s.size() && mySet.find(s[left]) == mySet.end()) {
                ++ left;
            }
            while (0 < right && mySet.find(s[right]) == mySet.end()) {
                -- right;
            }
            if (left < right) {
                swap(s[left], s[right]);
                ++ left;
                -- right;
            }
        }
        return s;
    }
};
// @lc code=end

