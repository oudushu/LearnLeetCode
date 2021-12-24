/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> myMap;
        for (string str : strs) {
            string str1 = str;
            sort(str1.begin(), str1.end());
            myMap[str1].push_back(str);
        }
        vector<vector<string>> res;
        for (auto it = myMap.begin(); it != myMap.end(); ++ it) {
            res.push_back(it->second);
        }
        return res;
    }
};
// @lc code=end

