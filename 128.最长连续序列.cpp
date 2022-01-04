/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> mySet;
        for (const int &num : nums) {
            mySet.insert(num);
        }
        int longestCon = 0;
        for (const int &num : mySet) {
            if (!mySet.count(num - 1)) {
                int curCon = 1;
                int cur = num;
                while (mySet.count(cur + 1)) {
                    cur ++;
                    curCon ++;
                }
                longestCon = max(curCon, longestCon);
            }
        }
        return longestCon;
    }
};
// @lc code=end

