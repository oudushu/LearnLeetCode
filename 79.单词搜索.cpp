/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
private:
    int path[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool track(vector<vector<char>>& board, string &word, vector<vector<int>> &visited, int i, int j, int index) {
        if (word[index] != board[i][j]) return false;
        if (index == word.size() - 1) return true;
        visited[i][j] = 1;
        for (int p = 0; p < 4; p ++) {
            int x = i + path[p][0];
            int y = j + path[p][1];
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y] == 1) {
                continue;
            }
            if (track(board, word, visited, x, y, index + 1)) {
                return true;
            }
        }
        visited[i][j] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> visited(row, vector(col, 0));
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                bool res = track(board, word, visited, i, j, 0);
                if (res) return true;
            }
        }
        return false;
    }
};
// @lc code=end

