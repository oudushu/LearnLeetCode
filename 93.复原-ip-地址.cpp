/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
private:
    const int kCount = 4;
    void trackback(vector<string>& res, vector<int>& track, string& s, int index) {
        if (track.size() == kCount) {
            if (s.size() == index) {
                string str;
                for (int i : track) {
                    str += to_string(i) + '.';
                }
                str.pop_back();
                res.push_back(str);
            }
            return;
        }
        if (index == s.size()) return;

        if (s[index] == '0') {
            track.push_back(0);
            trackback(res, track, s, index + 1);
            track.pop_back();
            return;
        }

        int addr = 0;
        for (int i = index; i < s.size(); ++i) {
            addr = addr * 10 + (s[i] - '0');
            if (addr > 0 && addr <= 0xFF) {
                track.push_back(addr);
                trackback(res, track, s, i + 1);
                track.pop_back();
            } else {
                break;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> track;
        trackback(res, track, s, 0);
        return res;
    }
};
// @lc code=end

