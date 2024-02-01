/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    // string countAndSay(int n) {
    //     string prev = "1";
    //     for (int i = 2; i <= n; ++i) {
    //         string curr = "";
    //         int start = 0;
    //         int pos = 0;

    //         while (pos < prev.size()) {
    //             while (pos < prev.size() && prev[pos] == prev[start]) {
    //                 pos++;
    //             }
    //             curr += to_string(pos - start) + prev[start];
    //             start = pos;
    //         }
    //         prev = curr;
    //     }
        
    //     return prev;
    // }

    string countAndSay(int n) {
        string lastStr = "1";
        for (int i = 1; i < n; ++i) {
            string tmpStr = "";
            for (int j = 0; j < lastStr.size(); ++j) {
                int start = j;
                while (j < lastStr.size() && lastStr[j + 1] == lastStr[start]) {
                    ++j;
                }
                tmpStr += to_string(j - start + 1) + lastStr[start];
            }
            lastStr = tmpStr;
        }
        return lastStr;
    }
};
// @lc code=end

string solve(string str) {
    string res;
    for (int i = 0; i < str.size(); ++i) {
        int start = i;
        while (i < str.size() && str[i + 1] == str[start]) {
            ++i;
        }
        res += to_string(i - start + 1) + str[start];
    }
    return res;
}