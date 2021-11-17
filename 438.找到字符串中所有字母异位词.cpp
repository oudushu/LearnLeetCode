/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sSize = s.size(), pSize = p.size();
        if (sSize < pSize) return {};
        vector<int> res, sArr(26), pArr(26);
        for (int i = 0; i < pSize; ++ i) {
            ++ sArr[s[i] - 'a'];
            ++ pArr[p[i] - 'a'];
        }
        if (sArr == pArr) {
            res.push_back(0);
        }
        for (int i = pSize; i < sSize; ++ i) {
            -- sArr[s[i - pSize] - 'a'];
            ++ sArr[s[i] - 'a'];
            if (sArr == pArr) {
                res.push_back(i - pSize + 1);
            }
        }
        return res;
    }
};
// @lc code=end

