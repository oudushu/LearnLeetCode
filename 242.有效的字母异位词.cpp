/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> myMap;
        for (char ch : s) {
            ++ myMap[ch];
        }
        for (char ch : t) {
            -- myMap[ch];
            if (myMap[ch] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

