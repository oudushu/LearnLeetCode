/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> res(size);
        for (int i = 0; i < size; ++ i) {
            res[(i + k) % size] = nums[i];
        }
        nums.assign(res.begin(), res.end());
    }
};
// @lc code=end

