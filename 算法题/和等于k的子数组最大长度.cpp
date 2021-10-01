#include <bits/stdc++.h>
using namespace std;
/** Leetcode 325 会员
 *  
 * 
 */

class Solution {
   public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        //利用前缀和数组 快速计算子数组的和
        //而又因为求的是最长子数组等于k，所以我们在哈希表中保存的是前缀和为x第一次出现的下标
        //然后我们求以每个元素为结尾的，最长 和等于k的子数组长度

        //值为x的前缀和最早出现的下标y  hash【x】=y
        unordered_map<int, int> hash;
        // 这个初始化很重要，为了考虑到 0~i等于k的情况
        hash[0] = -1;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (hash.count(sum - k)) res = max(res, i - hash[sum - k]);
            if (!hash.count(sum)) hash[sum] = i;  // 因为要的是第一次出现的值
        }
        return res;
    }
};
