/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
private:
    void trackback(vector<vector<int>> &res, vector<int> &track, vector<int>& candidates, int target, int index, vector<int> &used) {
        if (target == 0) {
            res.push_back(track);
            return;
        }
        for (int i = index; i < candidates.size(); i ++) {
            if (target - candidates[i] < 0 || (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == 0)) {
                continue;
            }
            track.push_back(candidates[i]);
            used[i] = 1;
            trackback(res, track, candidates, target - candidates[i], i + 1, used);
            used[i] = 0;
            track.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> track;
        vector<int> used(candidates.size(), 0);
        sort(candidates.begin(), candidates.end());
        trackback(res, track, candidates, target, 0, used);
        return res;
    }
};
// @lc code=end

