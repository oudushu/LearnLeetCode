/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
private:
    void dfs(string &s, vector<vector<string>> &res, vector<string> &track, int start, vector<vector<int>> &visited) {
        if (start == s.size()) {
            res.push_back(track);
            return;
        }

        for (int j = start; j < s.size(); ++ j) {
            if (isPalindrome(s, visited, start, j) == 1) {
                track.push_back(s.substr(start, j - start + 1));
                dfs(s, res, track, j + 1, visited);
                track.pop_back();
            }
        }
    }

    int isPalindrome(string &s, vector<vector<int>> &visited, int i, int j) {
        if (visited[i][j]) {
            return visited[i][j];
        }
        if (i >= j) {
            return visited[i][j] = 1;
        }
        return visited[i][j] = (s[i] == s[j] ? isPalindrome(s, visited, i + 1, j - 1) : -1);
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> track;
        vector<vector<int>> visited(s.size(), vector<int>(s.size()));
        dfs(s, res, track, 0, visited);
        return res;
    }
};
// @lc code=end

