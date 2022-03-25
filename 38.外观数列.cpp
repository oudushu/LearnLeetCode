/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        for (int i = 2; i <= n; ++i) {
            string curr = "";
            int start = 0;
            int pos = 0;

            while (pos < prev.size()) {
                while (pos < prev.size() && prev[pos] == prev[start]) {
                    pos++;
                }
                curr += to_string(pos - start) + prev[start];
                start = pos;
            }
            prev = curr;
        }
        
        return prev;
    }
};
// @lc code=end

void solve(string str) {
    string res;
    for (int i = 0; i < str.size(); ++i) {
        int start = i;
        while (i < str.size() && str[i] == str[start]) {
            ++i;
        }
        res += to_string(i - start + 1) + str[start];
    }
    return res;
}