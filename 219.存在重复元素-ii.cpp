/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++ i) {
            int num = nums[i];
            if (myMap.count(num) && i - myMap[num] <= k) {
                return true;
            }
            myMap[num] = i;
        }
        return false;
    }
};
// @lc code=end

