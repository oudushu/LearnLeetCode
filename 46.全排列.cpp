/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    void trackback(vector<vector<int>> &res, vector<int> &track, vector<int> &nums) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (find(track.begin(), track.end(), nums[i]) != track.end()) {
                continue;
            }
            track.push_back(nums[i]);
            trackback(res, track, nums);
            track.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        trackback(res, track, nums);
        return res;
    }
};
// @lc code=end

