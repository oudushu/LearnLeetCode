/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        vector<bool> visited(size, false);
        for (int i = 0; i < size; ++ i) {
            visited[nums[i]] = true;
        }
        for (int i = 0; i < size; ++ i) {
            if (!visited[i]) {
                return i;
            }
        }
        return size;
    }
};
// @lc code=end

