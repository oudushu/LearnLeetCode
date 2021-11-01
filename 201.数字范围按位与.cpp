/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            ++ count;
        }
        return (right << count);
    }
};
// @lc code=end

