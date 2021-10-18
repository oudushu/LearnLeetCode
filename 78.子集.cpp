/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    void trackback(vector<vector<int>> &res, vector<int> &track, vector<int> &nums, int index) {
        // if (index == nums.size()) {
        //     res.push_back(track);
        //     return;
        // }
        // track.push_back(nums[index]);
        // trackback(res, track, nums, index + 1);
        // track.pop_back();
        // trackback(res, track, nums, index + 1);

        res.push_back(track);
        for (int i = index; i < nums.size(); i ++) {
            track.push_back(nums[i]);
            trackback(res, track, nums, i + 1);
            track.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        trackback(res, track, nums, 0);
        return res;
    }
};
// @lc code=end

