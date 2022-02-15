/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
private:
    void dfs(string &s, vector<vector<string>> &res, vector<string> &track, int start) {
        if (start == s.size()) {
            res.push_back(track);
            return;
        }

        for (int j = start; j < s.size(); ++ j) {
            if (isPalindrome(s, start, j) == 1) {
                track.push_back(s.substr(start, j - start + 1));
                dfs(s, res, track, j + 1);
                track.pop_back();
            }
        }
    }

    int isPalindrome(string &s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) return 0;
            ++ i;
            -- j;
        }
        return 1;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> track;
        dfs(s, res, track, 0);
        return res;
    }
};
// @lc code=end

