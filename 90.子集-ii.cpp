/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
private:
    void trackback(vector<vector<int>> &res, vector<int> &track, vector<int> &nums, int start, vector<int> &used) {
        res.push_back(track);
        for (int i = start; i < nums.size(); ++i) {
            if (used[i] == 1 || (i > 0 && used[i] == used[i - 1] && used[i - 1] == 0)) {
                continue;
            }
            track.push_back(nums[i]);
            used[i] = 1;
            trackback(res, track, nums, i + 1, used);
            used[i] = 0;
            track.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        vector<int> used(nums.size(), 0);
        sort(nums.begin(), nums.end());
        trackback(res, track, nums,0, used);
        return res;
    }
};
// @lc code=end

