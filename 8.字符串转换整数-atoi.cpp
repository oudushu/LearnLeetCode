/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start

class Automaton {
public:
    long long res = 0;
    int sign = 1;
    string currentState = "start";
    map<string, vector<string>> stateMap = {
        {"start", {"start", "sign", "num", "end"}},
        {"sign", {"end", "end", "num", "end"}},
        {"num", {"end", "end", "num", "end"}},
        {"end", {"end", "end", "end", "end"}},
    };

    int getState(char c) {
        if (isspace(c)) return 0;
        if (c == '+' || c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }

    void put(char c) {
        currentState = stateMap[currentState][getState(c)];
        if (currentState == "num") {
            res = res * 10 + (c - '0');
            res = sign == 1 ? min(res, (long long)INT_MAX) : min(res, -(long long)INT_MIN);
        } else if (currentState == "sign") {
            sign = c == '-' ? -1 : 1;
        }
    }

};

class Solution {
public:
    int myAtoi(string s) {
        Automaton a;
        for (char ch : s) {
            a.put(ch);
        }
        return a.sign * a.res;
    }
};
// @lc code=end

