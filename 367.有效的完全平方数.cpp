/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long res = (long)mid * mid;
            if (res == num) {
                return true;
            } else if (res < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

