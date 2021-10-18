/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m - 1, index2 = n - 1, index = m + n - 1;
        while (index1 >= 0 || index2 >= 0) {
            int cur = 0;
            if (index1 < 0) {
                cur = nums2[index2 --];
            } else if (index2 < 0) {
                cur = nums1[index1 --];
            } else if (nums1[index1] < nums2[index2]) {
                cur = nums2[index2 --];
            } else {
                cur = nums1[index1 --];
            }
            nums1[index --] = cur;
        }
    }
};
// @lc code=end

