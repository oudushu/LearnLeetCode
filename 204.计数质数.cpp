/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
private:
    // bool isPrime(int n) {
    //     for (int i = 2; i * i <= n; ++ i) {
    //         if (n % i == 0) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
public:
    int countPrimes(int n) {
        // int res = 0;
        // for (int i = 2; i < n; ++ i) {
        //     res += isPrime(i);
        // }
        // return res;

        int res = 0;
        vector<bool> isPrime(n, true);
        for (int i = 2; i < n; ++ i) {
            if (isPrime[i]) {
                ++ res;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

