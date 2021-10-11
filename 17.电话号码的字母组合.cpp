/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void trackback(string &digits, vector<string> &res, string &track, int index) {
        if (track.size() == digits.size()) {
            res.push_back(track);
            return;
        }
        string numStr = phoneMap[digits[index]];
        for (int i = 0; i < numStr.size(); i ++) {
            track.push_back(numStr[i]);
            trackback(digits, res, track, index + 1);
            track.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string track;
        trackback(digits, res, track, 0);
        return res;
    }
};
// @lc code=end

