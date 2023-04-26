/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
private:
    const int TODO = 0;
    const int WORKING = 1;
    const int DONE = 2;

    bool dfs(int n, vector<int>& res, vector<vector<int>>& edge, vector<int>& visited) {
        if (visited[n] == WORKING) return false;
        if (visited[n] == DONE) return true;
        visited[n] = WORKING;
        for (int i : edge[n]) {
            if (!dfs(i, res, edge,visited)) {
                return false;
            }
        }
        visited[n] = DONE;
        res.push_back(n);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, TODO);
        vector<vector<int>> edge(numCourses, vector<int>());
        vector<int> res;
        for (auto& info : prerequisites) {
            edge[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == TODO && !dfs(i, res, edge, visited)) {
                return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

