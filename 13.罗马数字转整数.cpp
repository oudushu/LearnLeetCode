/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0;
        int n = s.size();
        for (int i = 0; i < n; i ++) {
            int val = dict[s[i]];
            if (i + 1 < n && val < dict[s[i + 1]]) {
                res -= val;
            } else {
                res += val;
            }
        }
        return res;
    }
};
// @lc code=end

