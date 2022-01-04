/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
private:
    int const segmentCount = 4;

    void dfs(vector<string> &res, vector<int> &segment, string &s, int count, int start) {
        if (segmentCount == count) {
            if (start == s.size()) {
                string ipAddr;
                for (int i = 0; i < segmentCount; ++ i) {
                    ipAddr += to_string(segment[i]);
                    if (i != segmentCount - 1) {
                        ipAddr += '.';
                    }
                }
                res.push_back(ipAddr);
            }
            return;
        }

        if (start == s.size()) {
            return;
        }

        if (s[start] == '0') {
            segment[count] = 0;
            dfs(res, segment, s, count + 1, start + 1);
            return;
        }

        int addr = 0;
        for (int i = start; i < s.size(); ++ i) {
            addr = addr * 10 + (s[i] - '0');
            if (addr > 0 && addr <= 0xFF) {
                segment[count] = addr;
                dfs(res, segment, s, count + 1, i + 1);
            } else {
                break;
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> segment(segmentCount, 0);
        vector<string> res;
        dfs(res, segment, s, 0, 0);
        return res;
    }
};
// @lc code=end

