/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> result;
    bool isValid = true;

    void dfs(int u) {
        visited[u] = 1;
        for (int v : edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!isValid) {
                    return;
                }
            } else if (visited[v] == 1) {
                isValid = false;
                return;
            }
        }
        visited[u] = 2;
        result.push_back(u);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto &info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && isValid; ++ i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        if (!isValid) {
            return {};
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

