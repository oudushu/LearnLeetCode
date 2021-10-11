/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int pal = 0;
        while (x > pal) {
            pal = pal * 10 + x % 10;
            x /= 10;
        }
        return x == pal || x == pal / 10;
    }
};
// @lc code=end

