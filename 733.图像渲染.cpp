/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
private:
    int path[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void fill(vector<vector<int>> &image, int i, int j, int newColor, int oldColor) {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size()) {
            return;
        }
        if (image[i][j] == oldColor) {
            image[i][j] = newColor;
            for (int p = 0; p < 4; ++ p) {
                int x = i + path[p][0];
                int y = j + path[p][1];
                fill(image, x, y, newColor, oldColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        fill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};
// @lc code=end

