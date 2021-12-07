/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), count = 0, maxVal = 0;
        vector<vector<int>> seen(row, vector<int>(col));
        vector<vector<int>> res(row, vector<int>(col));
        queue<pair<int, int>> myQueue;
        for (int i = 0; i < row; ++ i) {
            for (int j = 0; j < col; ++ j) {
                if (grid[i][j] == 2) {
                    seen[i][j] = 1;
                    myQueue.emplace(i, j);
                } else if (grid[i][j] == 1) {
                    ++ count;
                }
            }
        }
        int path[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!myQueue.empty()) {
            auto [i, j] = myQueue.front();
            myQueue.pop();
            for (int p = 0; p < 4; ++ p) {
                int x = i + path[p][0];
                int y = j + path[p][1];
                if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == 0 || seen[x][y] == 1) {
                    continue;
                }
                seen[x][y] = 1;
                res[x][y] = res[i][j] + 1;
                myQueue.emplace(x, y);
                if (grid[x][y] == 1) {
                    maxVal = max(maxVal, res[x][y]);
                    -- count;
                }
            }
        }
        return count > 0 ? -1 : maxVal;
    }
};
// @lc code=end

