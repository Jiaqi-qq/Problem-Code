#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    /**
     * 在数组中找到 两数之和最接近 sum 的全部组合。升序返回
     *
     * 返回值是1个二维数组，表示多个可能的组合；要求返回的是索引
     * @param array int整型vector 给定的数组（没有重复数字，长度至少等于2）
     * @param sum int整型 两数之和要等于这个sum
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> twoSum(vector<int> &array, int sum) {
        // write code here
        vector<vector<int>> ans;
        if (array.size() < 2) return ans;
        vector<int> index(array.size());
        for (int i = 0; i < index.size(); ++i) index[i] = i;
        int dif = INT_MAX;
        sort(index.begin(), index.end(), [&](int x, int y) { return array[x] < array[y]; });

        for (int i = 0; i < index.size(); ++i) {
            auto p = lower_bound(index.begin(), index.end(), sum - array[index[i]], [&](int tmp, int x) { return array[tmp] < array[x]; });
            printf("\tp:%d\n", p - index.begin());
            if (p != index.end() && array[*p] != array[index[i]]) {
                // printf("1 : %d + %d, dif:%d\n", array[index[i]], array[*p], abs(sum - array[index[i]] - *p));
                dif = min(dif, abs(sum - array[index[i]] - array[*p]));
                if (p + 1 != index.end() && array[*(p + 1)] != array[index[i]]) {
                    // printf("3 : %d + %d, dif:%d\n", array[index[i]], array[*(p - 1)], abs(sum - array[index[i]] - *(p + 1)));
                    dif = min(dif, abs(sum - array[index[i]] - array[*(p + 1)]));
                }
            }
            if (p != index.begin() && array[*(p - 1)] != array[index[i]]) {
                // printf("2 : %d + %d, dif:%d\n", array[index[i]], array[*(p - 1)], abs(sum - array[index[i]] - *(p - 1)));
                dif = min(dif, abs(sum - array[index[i]] - array[*(p - 1)]));
            }
        }
        printf("dif:%d\n", dif);
        map<int, int> mp;
        for (int i = 0; i < index.size(); ++i) {
            if (dif == 0) {
                if (mp.find(sum - array[index[i]]) != mp.end()) {
                    if (mp[sum - array[index[i]] - dif] < index[i])
                        ans.push_back({mp[sum - array[index[i]] - dif], index[i]});
                    else
                        ans.push_back({index[i], mp[sum - array[index[i]] - dif]});
                }
            } else {
                if (mp.find(sum - array[index[i]] - dif) != mp.end()) {
                    if (mp[sum - array[index[i]] - dif] < index[i])
                        ans.push_back({mp[sum - array[index[i]] - dif], index[i]});
                    else
                        ans.push_back({index[i], mp[sum - array[index[i]] - dif]});
                }
                if (mp.find(sum - array[index[i]] + dif) != mp.end()) {
                    if (mp[sum - array[index[i]] + dif] < index[i])
                        ans.push_back({mp[sum - array[index[i]] + dif], index[i]});
                    else
                        ans.push_back({index[i], mp[sum - array[index[i]] + dif]});
                }
            }
            mp[array[index[i]]] = index[i];
        }
        sort(ans.begin(), ans.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });

        return ans;
    }
};