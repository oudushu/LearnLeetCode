/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
private:
    void dfs(vector<vector<int>> &isConnected, vector<int> &isVisited, int i) {
        for (int j = 0; j < isConnected.size(); ++ j) {
            if (isVisited[j] != 1 && isConnected[i][j] == 1) {
                isVisited[j] = 1;
                dfs(isConnected, isVisited, j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        int count = 0;
        vector<int> isVisited(size);
        for (int i = 0; i < size; ++ i) {
            if (!isVisited[i]) {
                dfs(isConnected, isVisited, i);
                ++ count;
            }
        }
        return count;
    }
};
// @lc code=end

