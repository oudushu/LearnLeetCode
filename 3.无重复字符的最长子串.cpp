/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size == 0) return 0;
        set<char> mySet;
        int longest = 0;
        int j = 0;
        for (int i = 0; i < size; ++ i) {
            if (i > 0) {
                mySet.erase(s[i - 1]);
            }
            while (j < size && mySet.find(s[j]) == mySet.end()) {
                mySet.insert(s[j]);
                ++ j;
            }
            longest = max(longest, j - i);
        }
        return longest;
    }
};
// @lc code=end

