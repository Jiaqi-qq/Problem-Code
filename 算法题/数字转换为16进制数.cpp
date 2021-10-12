#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string toHex(int num) {
        string res;
        long long N = num;
        if (N == 0) return "0";
        string dict = "0123456789abcdef";
        if (N < 0) N = N + 0x100000000; /* 负数的补码: 其数字范围就是0到UINT_MAX(2^31-1), 即为16^8-1。
										这里+ 0x100000000是为了将任意一个负数转换到正数范围内(且不影响计算结果), 
										理论上±2^32均可, 但我们后面的迭代需要是正数, 于是选择+0x100000000。 */
        while (N > 0) {
            long long lastDigit = N % 16;
            N /= 16;
            res = dict[lastDigit] + res;
        }
        return res;
    }
};
