/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            long sx = 10, sy = 10;
            while (sx <= x) {
                sx *= 10;
            }
            while (sy <= y) {
                sy *= 10;
            }
            return sx * y + x < sy * x + y;
        });
        if (nums[0] == 0) return "0";
        string res;
        for (auto &num : nums) {
            res += to_string(num);
        }
        return res;
    }
};
// @lc code=end

