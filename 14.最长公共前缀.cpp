/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.size() == 0) return res;
        for (int i = 0; i < strs[0].size(); i ++) {
            for (int j = 0; j < strs.size(); j ++) {
                if (strs[j][i] != strs[0][i]) {
                    return res;
                }
            }
            res += strs[0][i];
        }
        return res;
    }
};
// @lc code=end

