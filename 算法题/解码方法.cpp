/* Leetcode 91 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        auto check = [&](char i, char j) -> bool {
            if(i == '0' || i > '2') return false;
            if(i == '1') return true;
            if(i == '2') return j <= '6';
            return false;
        };
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != '0')
                dp[i + 1] += dp[i];
            if(i > 0 && check(s[i - 1], s[i])) {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[s.size()];
    }
};

int main(){
	Solution sol;
    cout << sol.numDecodings("12") << endl;
}