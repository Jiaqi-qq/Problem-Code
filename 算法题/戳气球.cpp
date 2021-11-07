#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        // [1, 3, 1, 5, 8, 1]

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        auto print = [&dp]() {
            printf("  ");
            for (int i = 0; i < dp[0].size(); ++i) {
                printf("%5d", i);
            }
            printf("\n");
            for (int i = 0; i < dp.size(); ++i) {
                printf("%d:", i);
                for (auto y : dp[i]) {
                    printf("%5d", y);
                }
                cout << endl;
            }
            cout << endl;
        };
        for (int len = 3; len <= nums.size(); ++len) {
            for (int i = 0; i <= nums.size() - len; ++i) {
                int j = i + len - 1;  // [i, j] 长度 len
                if (j > nums.size()) break;
                for (int k = i + 1; k < j; k++) {  // k在(i, j)开区间内枚举位置
                    dp[i][j] = max(dp[i][j], dp[i][k] + nums[i] * nums[k] * nums[j] + dp[k][j]);
                }
                printf("[%d,%d]\n", i, j);
                print();
            }
        }
        return dp[0][nums.size() - 1];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 5, 8};
    cout << sol.maxCoins(arr) << endl;
}