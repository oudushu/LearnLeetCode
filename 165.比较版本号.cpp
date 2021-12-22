/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, m = version1.size(), n = version2.size();
        while (i < m || j < n) {
            int x = 0;
            while (i < m && version1[i] != '.') {
                x = x * 10 + (version1[i] - '0');
                ++ i;
            }
            ++ i;

            int y = 0;
            while (j < n && version2[j] != '.') {
                y = y * 10 + (version2[j] - '0');
                ++ j;
            }
            ++ j;

            if (x != y) {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};
// @lc code=end

