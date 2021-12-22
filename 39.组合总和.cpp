/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    void trackback(vector<vector<int>> &res, vector<int> &track, vector<int>& candidates, int target, int index) {
        if (target == 0) {
            res.push_back(track);
            return;
        }
        for (int i = index; i < candidates.size(); ++ i) {
            if (target - candidates[i] < 0) {
                continue;
            }
            track.push_back(candidates[i]);
            trackback(res, track, candidates, target - candidates[i], i);
            track.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> track;
        trackback(res, track, candidates, target, 0);
        return res;
    }
};
// @lc code=end

