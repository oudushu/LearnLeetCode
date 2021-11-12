/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        map<int, int> myMap;
        for (int num : nums1) {
            ++ myMap[num];
        }
        vector<int> res;
        for (int num : nums2) {
            if (myMap.count(num)) {
                res.push_back(num);
                -- myMap[num];
                if (myMap[num] == 0) {
                    myMap.erase(num);
                }
            }
        }
        return res;
    }
};
// @lc code=end

