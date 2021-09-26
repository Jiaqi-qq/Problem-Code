#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 7;
int a[maxn];
int dp[maxn];

int pos[maxn];
int ans[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    memset(pos, 0, sizeof(pos));
    int len = 1;
    dp[1] = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > dp[len]) {
            dp[++len] = a[i];
            ::pos[i] = len;
        } else {
            int pos = lower_bound(dp + 1, dp + 1 + len, a[i]) - dp;
            dp[pos] = a[i];
            ::pos[i] = pos;
        }
    }
    cout << len << endl;

    int t = len;
    for (int i = n - 1; i >= 0; --i) {
        if (!len) {
            break;
        }
        if (pos[i] == len) {
            ans[len] = i;
            --len;
        }
    }

    for (int i = 1; i <= t; ++i) {
        cout << a[ans[i]] << " ";
    }
    cout << endl;
    return 0;
}
