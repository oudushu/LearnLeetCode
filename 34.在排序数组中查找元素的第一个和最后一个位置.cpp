/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); i ++) {
//             if (nums[i] == target) {
//                 int left = i, right = i;
//                 while (right + 1 < nums.size() && nums[right + 1] == target) {
//                     right ++;
//                 }
//                 return {left, right};
//             }
//         }
//         return {-1, -1};
//     }
// };

class Solution {
private:
    int search(vector<int> &nums, int target, bool lower) {
        int left = 0, right = nums.size() - 1;
        int res = nums.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target || (nums[mid] >= target && lower)) {
                right = mid - 1;
                res = mid;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = search(nums, target, true);
        int right = search(nums, target, false) - 1;
        if (left <= right && left >= 0 && right < nums.size() && nums[left] == target && nums[right] == target) {
            return {left, right};
        } 
        return {-1, -1};
    }
};
// @lc code=end

