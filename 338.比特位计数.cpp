/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; ++ i) {
            int count = 0;
            for (int j = 0; j < 32; ++ j) {
                if (i & (1 << j)) {
                    ++ count;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};
// @lc code=end

