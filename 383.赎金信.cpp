/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        map<char, int> myMap;
        for (char ch : magazine) {
            myMap[ch] ++;
        }
        for (char ch : ransomNote) {
            if (myMap.count(ch) > 0) {
                myMap[ch] --;
                if (myMap[ch] == 0) {
                    myMap.erase(ch);
                }
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

