/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxCount = 0, maxNum = 0;
        unordered_map<int, int> myMap;
        for (int num : nums) {
            ++ myMap[num];
            if (myMap[num] > maxCount) {
                maxCount = myMap[num];
                maxNum = num;
            }
        }
        return maxNum;
    }
};
// @lc code=end

