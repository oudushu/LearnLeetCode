/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for (int i = size - 1; i >= 0; -- i) {
            if (digits[i] != 9) {
                ++ digits[i];
                for (int j = i + 1; j < size; ++ j) {
                    digits[j] = 0;
                }
                return digits;
            }
        }

        vector<int> res(size + 1);
        res[0] = 1;
        return res;
    }
};
// @lc code=end

