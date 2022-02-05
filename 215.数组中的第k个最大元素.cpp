/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
private:
    int quickSort(vector<int> &nums, int k, int left, int right) {
        int i = left, j = right;
        int flag = nums[left];
        while (i < j) {
            while (i < j && nums[j] <= flag) {
                -- j;
            }
            nums[i] = nums[j];
            while (i < j && nums[i] >= flag) {
                ++ i;
            }
            nums[j] = nums[i];
        }
        nums[i] = flag;
        if (k == i + 1) {
            return nums[i];
        } else if (k < i + 1) {
            return quickSort(nums, k, left, i - 1);
        } else {
            return quickSort(nums, k, i + 1, right);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, k, 0, nums.size() - 1);
    }
};
// @lc code=end

