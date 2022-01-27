/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool isValid = true;

    void dfs(int c) {
        visited[c] = 1;
        for (int v : edges[c]) {
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
        visited[c] = 2;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        return isValid;
    }
};
// @lc code=end

