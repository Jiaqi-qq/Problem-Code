#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();

        int *dp = new int[len2 + 1];
        memset(dp, 0, sizeof(int) * (len2 + 1));

        for (int i = 1; i <= len1; ++i) {
            int last = 0; // dp[i - 1][j - 1]
            for (int j = 1; j <= len2; ++j) {
                int temp = dp[j]; // dp[i - 1][j]
                if (text1[i - 1] == text2[j - 1])
                    dp[j] = last + 1; // 改完后, dp[j] 表示 dp[i][j]
                else
                    dp[j] = max(dp[j - 1], dp[j]);
                last = temp; // 每次更新 last，确保在下一次迭代时，last
                             // 指向的是那个状态的 dp[i - 1][j - 1]
            }
        }
        return dp[len2];
    }
};

int main() {
    Solution sol;
    cout << sol.longestCommonSubsequence("1a2c3d4e56", "a1b2345c6d") << endl;
}
