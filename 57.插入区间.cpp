/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0], right = newInterval[1];
        vector<vector<int>> res;
        bool place = false;
        for (vector<int> interval : intervals) {
            if (interval[0] > right) {
                if (!place) {
                    res.push_back({left, right});
                    place = true;
                }
                res.push_back(interval);
            } else if (interval[1] < left) {
                res.push_back(interval);
            } else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!place) {
            res.push_back({left, right});
        }
        return res;
    }
};
// @lc code=end

