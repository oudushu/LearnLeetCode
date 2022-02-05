/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
private:
    void trackback(vector<vector<int>> &res, vector<int> &track, int &k, int sum, int begin) {
        if (sum == 0 && track.size() == k) {
            res.push_back(track);
            return;
        }
        for (int i = begin; i <= 9; ++ i) {
            track.push_back(i);
            trackback(res, track, k, sum - i, i + 1);
            track.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> track;
        trackback(res, track, k, n, 1);
        return res;
    }
};
// @lc code=end

