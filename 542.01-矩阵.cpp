/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
private:
    int path[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> res(row, vector<int>(col));
        vector<vector<int>> visited(row, vector<int>(col));
        queue<pair<int, int>> myQueue;
        for (int i = 0; i < row; ++ i) {
            for (int j = 0; j < col; ++ j) {
                if (mat[i][j] == 0) {
                    myQueue.push({i, j});
                    visited[i][j] = 1;
                    res[i][j] = 0;
                }
            }
        }

        while(!myQueue.empty()) {
            int size = myQueue.size();
            for (int i = 0; i < size; ++ i) {
                auto[x, y] = myQueue.front();
                myQueue.pop();
                for (int p = 0; p < 4; ++ p) {
                    int x1 = x + path[p][0];
                    int y1 = y + path[p][1];
                    if (x1 >= 0 && x1 < row && y1 >= 0 && y1 < col && visited[x1][y1] == 0) {
                        myQueue.push({x1, y1});
                        res[x1][y1] = res[x][y] + 1;
                        visited[x1][y1] = 1;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

