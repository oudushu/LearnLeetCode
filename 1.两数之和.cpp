/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> myMap;
        for (int i = 0; i < nums.size(); i ++) {
            if (myMap.find(target - nums[i]) != myMap.end()) {
                return {myMap[target - nums[i]], i};
            }
            myMap[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

