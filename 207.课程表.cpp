/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#define TODOIT   0
#define WORKING  1
#define FINISHED 2

class Solution {
private:
    bool dfs(vector<vector<int>> &adj, vector<int> &visited, int v) {
        if (visited[v] == WORKING) return false;
        if (visited[v] == FINISHED) return true;
        visited[v] = WORKING;
        for (int u : adj[v]) {
            if (!dfs(adj, visited, u)) {
                return false;
            }
        }
        visited[v] = FINISHED;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, TODOIT);
        vector<vector<int>> adj(numCourses, vector<int>());
        for (auto &info : prerequisites) {
            adj[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == TODOIT && !dfs(adj, visited, i)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

