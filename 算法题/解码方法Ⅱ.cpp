/* Leetcode 639 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
  private:
    static constexpr int mod = 1000000007;

  public:
    int numDecodings(string s) {
        auto check1digit = [](char ch) -> int {
            if (ch == '0') {
                return 0;
            }
            return ch == '*' ? 9 : 1;
        };

        auto check2digits = [](char c0, char c1) -> int {
            if (c0 == '*' && c1 == '*') {
                return 15;
            }
            if (c0 == '*') {
                return c1 <= '6' ? 2 : 1;
            }
            if (c1 == '*') {
                if (c0 == '1') {
                    return 9;
                }
                if (c0 == '2') {
                    return 6;
                }
                return 0;
            }
            return c0 != '0' && (c0 - '0') * 10 + (c1 - '0') <= 26;
        };

        // a = f[i-2], b = f[i-1], c = f[i]
        int a = 0, b = 1, c = 0;
        for (int i = 1; i <= s.size(); ++i) {
            c = (long long)b * check1digit(s[i - 1]) % mod;
            if (i > 1) {
                c = (c + (long long)a * check2digits(s[i - 2], s[i - 1])) % mod;
            }
            a = b;
            b = c;
        }
        return c;
    }
};

int main() {
    Solution sol;
    cout << sol.numDecodings("12") << endl;
}