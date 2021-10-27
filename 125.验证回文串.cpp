/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string tmpStr;
        for (char ch : s) {
            if (isalnum(ch)) {
                tmpStr += tolower(ch);
            }
        }
        int left = 0, right = tmpStr.size() - 1;
        while (left < right) {
            if (tmpStr[left] != tmpStr[right]) {
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
};
// @lc code=end

