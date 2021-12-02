/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>> &res, vector<int> &track, int index, int total) {
        if (index == total) {
            res.push_back(track);
            return;
        }
        for (auto &y : graph[index]) {
            track.push_back(y);
            dfs(graph, res, track, y, total);
            track.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> track;
        track.push_back(0);
        dfs(graph, res, track, 0, graph.size() - 1);
        return res;
    }
};
// @lc code=end

