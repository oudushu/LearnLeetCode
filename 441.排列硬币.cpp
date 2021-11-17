/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int total = n, index = 0;
        while (total > index) {
            ++ index;
            total = total - index;
        }
        return index;
    }
};
// @lc code=end

