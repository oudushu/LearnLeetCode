/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string, char> strToCh;
        map<char, string> chToStr;
        int size = s.size();
        int i = 0;
        for (char ch : pattern) {
            if (i >= size) return false;
            int j = i;
            while (j < size && s[j] != ' ') {
                ++ j;
            }
            string str = s.substr(i, j - i);
            if (strToCh.count(str) && strToCh[str] != ch) {
                return false;
            }
            if (chToStr.count(ch) && chToStr[ch] != str) {
                return false;
            }
            strToCh[str] = ch;
            chToStr[ch] = str;
            i = j + 1;
        }
        return i >= size;
    }
};
// @lc code=end

