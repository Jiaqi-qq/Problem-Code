#include <bits/stdc++.h>
using namespace std;

/**
 * 给定一个int数组(长度>2)，以及1个整数，在该数组中找到2个数，使得这两数之和等于/最接近给定的这个数
 * 注意：
 *      数组中不会有重复的数字。
 *      要求返回索引，而不是数组中的值。
 *      返回全部组合，并保证索引递增。
 * 例子：
 *      输入：[1,2,3,4,5,6], sum=5
 *      返回：[[0, 3], [1, 2]]
 * 
 *      输入：[9,0,1,4,5,3], sum=11
 *      返回：[[0, 1], [0, 2], [3, 4]]
 */
class Solution {
   public:
    /**
     * 返回值是1个二维数组，表示多个可能的组合；要求返回的是索引
     * @param array int整型vector 给定的数组（没有重复数字，长度至少等于2）
     * @param sum int整型 两数之和要等于这个sum
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> twoSum(vector<int> &array, int sum) {
        // write code here
        vector<vector<int>> ans;
        if (array.size() < 2) return ans;
        vector<int> index(array.size());  // 使用中间index进行排序，不改变原数组，便于最后找到初始索引
        for (int i = 0; i < index.size(); ++i) index[i] = i;
        int dif = INT_MAX;
        sort(index.begin(), index.end(), [&](int x, int y) { return array[x] < array[y]; });

        for (int i = 0; i < index.size(); ++i) {
            int t = sum - array[index[i]];
            // 二分找到 t 的位置
            auto p = lower_bound(index.begin(), index.end(), t, [&](int tmp, int x) { return array[tmp] < array[x]; });  // cmp：true 往右，false 往左
            // 如果存在这个数，那么就是 p；如果不存在，那就从 p-1 和 p 中选最近的
            if (p != index.end() && array[*p] != array[index[i]]) {
                dif = min(dif, abs(t - array[*p]));
            }
            if (p != index.begin() && array[*(p - 1)] != array[index[i]]) {
                dif = min(dif, abs(t - array[*(p - 1)]));
            }
        }
        // cout << "dif:" << dif << endl;
        map<int, int> mp;
        for (int i = 0; i < index.size(); ++i) {
            int t = sum - array[index[i]];
            if (dif == 0) {
                if (mp.find(t) != mp.end()) {
                    if (mp[t - dif] < index[i])
                        ans.push_back({mp[t - dif], index[i]});
                    else
                        ans.push_back({index[i], mp[t - dif]});
                }
            } else {
                if (mp.find(t - dif) != mp.end()) {
                    if (mp[t - dif] < index[i])
                        ans.push_back({mp[t - dif], index[i]});
                    else
                        ans.push_back({index[i], mp[t - dif]});
                }
                if (mp.find(t + dif) != mp.end()) {
                    if (mp[t + dif] < index[i])
                        ans.push_back({mp[t + dif], index[i]});
                    else
                        ans.push_back({index[i], mp[t + dif]});
                }
            }
            mp[array[index[i]]] = index[i];
        }
        sort(ans.begin(), ans.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });

        return ans;
    }
};

int main() {
    Solution sol;
    // vector<int> vec{9, 0, 2, 4, 5, 3};
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    auto ans = sol.twoSum(vec, 11);
    for_each(ans.cbegin(), ans.cend(), [](const vector<int> &x) { cout << x[0] << " " << x[1] << endl; });
}