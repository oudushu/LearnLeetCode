/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        for (int num : nums1) {
            set1.insert(num);
        }
        for (int num : nums2) {
            set2.insert(num);
        }
        vector<int> res;
        for (int num : set1) {
            if (set2.count(num)) {
                res.push_back(num);
            }
        }
        return res;
    }
};
// @lc code=end

