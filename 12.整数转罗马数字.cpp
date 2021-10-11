/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        map<int, string> dict = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"},
        };

        string res;
        for (auto val = dict.rbegin(); val != dict.rend(); val ++) {
            while (num / val->first) {
                num -= val->first;
                res += val->second;
            }
            if (num == 0) break;
        }
        return res;
    }
};
// @lc code=end

