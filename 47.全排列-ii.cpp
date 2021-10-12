/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
private:
    void trackback(vector<vector<int>> &res, vector<int> &track, vector<int> &nums, vector<int> &used) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (used[i] == 1 || (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)) {
                continue;
            }
            track.push_back(nums[i]);
            used[i] = 1;
            trackback(res, track, nums, used);
            used[i] = 0;
            track.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        vector<int> used(nums.size(), 0);
        sort(nums.begin(), nums.end());
        trackback(res, track, nums, used);
        return res;
    }
};
// @lc code=end

