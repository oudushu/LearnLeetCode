/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> myMap;
        for (char ch : s) {
            ++ myMap[ch];
        }
        for (char ch : t) {
            -- myMap[ch];
            if (myMap[ch] < 0) {
                return ch;
            }
        }
        return ' ';
    }
};
// @lc code=end

