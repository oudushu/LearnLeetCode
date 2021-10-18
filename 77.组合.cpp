/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
private:
    void trackback(vector<vector<int>> &res, vector<int> &track, int n, int k, int index) {
        if (k == track.size()) {
            res.push_back(track);
            return;
        }
        for (int i = index; i <= n; i ++) {
            track.push_back(i);
            trackback(res, track, n, k, i + 1);
            track.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> track;
        trackback
    }
};
// @lc code=end

