/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
private:
    int path[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>> &grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1') {
            return;
        }
        grid[x][y] = '0';
        for (int p = 0; p < 4; ++ p) {
            int i = path[p][0] + x;
            int j = path[p][1] + y;
            dfs(grid, i, j);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++ i) {
            for (int j = 0; j < grid[0].size(); ++ j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++ res;
                }
            }
        }
        return res;
    }
};
// @lc code=end

