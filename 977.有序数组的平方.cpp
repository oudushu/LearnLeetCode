/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size);
        int i = 0, j = size - 1, pos = size - 1;
        while (i <= j) {
            int squareI = nums[i] * nums[i];
            int squareJ = nums[j] * nums[j];
            if (squareI > squareJ) {
                res[pos] = squareI;
                i ++;
            } else {
                res[pos] = squareJ;
                j --;
            }
            pos --;
        }
        return res;
    }
};
// @lc code=end

