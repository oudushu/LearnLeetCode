/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> myMap;
        for (char ch : s) {
            ++ myMap[ch];
        }
        for (int i = 0; i < s.size(); i ++) {
            char ch = s[i];
            if (myMap.count(ch)) {
                if (myMap[ch] == 1) {
                    return i;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

