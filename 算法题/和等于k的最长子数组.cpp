#include <bits/stdc++.h>
using namespace std;
/** 
 *  
 * 
 */

class Solution {
   public:
    vector<int> maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        vector<int> ans;
        // 这个初始化很重要，为了考虑到 0~i等于k的情况
        hash[0] = -1;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (hash.count(sum - k) && maxLen < i - hash[sum - k]) {
                maxLen = i - hash[sum - k];
                ans.assign(nums.begin() + i - maxLen, nums.begin() + i);
            }
            if (!hash.count(sum)) hash[sum] = i;  // 因为要的是第一次出现的值
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto ans = sol.maxSubArrayLen(vec, 18);
    for_each(ans.cbegin(), ans.cend(), [](const int& x) { cout << x << " "; });
}