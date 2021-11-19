/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int>> res(size, vector<int>(size));
        for (int i = size - 1; i >= 0; -- i) {
            res[i][i] = 1;
            for (int j = i + 1; j < size; ++ j) {
                if (s[i] == s[j]) {
                    res[i][j] = res[i + 1][j - 1] + 2;
                } else {
                    res[i][j] = max(res[i + 1][j], res[i][j - 1]);
                }
            }
        }
        return res[0][size - 1];
    }
};
// @lc code=end

