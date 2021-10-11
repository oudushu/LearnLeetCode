/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
private:
    void trackback(vector<string> &res, string &track, int left, int right, int n) {
        if (track.size() == n * 2) {
            res.push_back(track);
            return;
        }
        if (left < n) {
            track.push_back('(');
            trackback(res, track, left + 1, right, n);
            track.pop_back();
        }
        if (right < left) {
            track.push_back(')');
            trackback(res, track, left, right + 1, n);
            track.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string track;
        trackback(res, track, 0, 0, n);
        return res;
    }
};
// @lc code=end

