/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size(), size2 = s2.size();
        if (size1 > size2) {
            return false;
        }
        vector<int> arr1(26);
        vector<int> arr2(26);
        for (int i = 0; i < size1; ++ i) {
            ++ arr1[s1[i] - 'a'];
            ++ arr2[s2[i] - 'a'];
        }
        if (arr1 == arr2) {
            return true;
        }
        for (int i = size1; i < size2; ++ i) {
            -- arr2[s2[i - size1] - 'a'];
            ++ arr2[s2[i] - 'a'];
            if (arr1 == arr2) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

