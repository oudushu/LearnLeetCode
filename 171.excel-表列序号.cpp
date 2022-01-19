/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        if (columnTitle.size() == 0) return 0;
        int res = 0;
        for (int i = 0; i < columnTitle.size(); ++ i) {
            int val = columnTitle[i] - 'A' + 1;
            res = res * 26 + val;
        }
        return res;
    }
};
// @lc code=end

