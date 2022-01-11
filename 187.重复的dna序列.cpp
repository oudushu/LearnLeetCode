/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() < 10) return res;
        map<string, int> myMap;
        const int length = 10;
        for (int i = 0; i <= s.size() - length; ++ i) {
            string sub = s.substr(i, 10);
            int count = ++ myMap[sub];
            if (count == 2) {
                res.push_back(sub);
            }
        }
        return res;
    }
};
// @lc code=end

