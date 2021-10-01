#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); ++i)
            dp[i][i] = true;
        int l = 0, r = 0;
        for (int len = 2; len <= s.size(); ++len) {
            for (int i = 0; i < s.size(); ++i) {
                int j = i + len - 1; // [i, j]
                if (j >= s.size())
                    break;
                if (s[i] == s[j] && (dp[i + 1][j - 1] || len == 2)) {
                    l = i, r = j;
                    dp[i][j] = true;
                }
            }
        }
        return s.substr(l, r - l + 1);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("cbbd") << endl;
}