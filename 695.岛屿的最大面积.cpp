/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
private:
    int path[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return 0;
        }
        if (grid[i][j] != 0) {
            grid[i][j] = 0;
            int res = 0;
            for (int p = 0; p < 4; ++ p) {
                int x = i + path[p][0];
                int y = j + path[p][1];
                res += dfs(grid, x, y);
            }
            return res + 1;
        }
        return 0;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++ i) {
            for (int j = 0; j < grid[0].size(); ++ j) {
                if (grid[i][j] != 0) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }
};
// @lc code=end

