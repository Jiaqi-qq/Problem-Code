#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') return true;
    return false;
}

int getPriority(char ch) {
    int level = 0;
    switch (ch) {
        case '(':
            level = 1;
            break;
        case '+':
        case '-':
            level = 2;
            break;
        case '*':
        case '/':
            level = 3;
            break;
    }
    return level;
}

ll calc(ll a, ll b, char sym) {
    switch (sym) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return -1;
}

ll calc(string s) {
    size_t i = 0;
    stack<ll> num;
    stack<char> sym;
    while (i < s.size()) {
        string nums;
        if (isdigit(s[i])) {
            while (isdigit(s[i]))
                nums += s[i++];
            num.push(stoll(nums));

            if (i == s.size()) break;
        }
        char symb = s[i++];
        if (isOperator(symb)) {
            if (sym.empty()) {
                sym.push(symb);
            } else {
                while (getPriority(symb) <= getPriority(sym.top())) {
                    ll num2 = num.top();
                    num.pop();
                    ll num1 = num.top();
                    num.pop();
                    char symbol = sym.top();
                    sym.pop();
                    num.push(calc(num1, num2, symbol));
                    if (sym.empty()) break;
                }
                sym.push(symb);
            }
        } else {
            if (symb == '(') {
                sym.push(symb);
            } else if (symb == ')') {
                while (sym.top() != '(') {
                    char symbol = sym.top();
                    sym.pop();
                    ll num2 = num.top();
                    num.pop();
                    ll num1 = num.top();
                    num.pop();
                    num.push(calc(num1, num2, symbol));
                }
                sym.pop();
            }
        }
    }
    while (!sym.empty()) {
        ll num2 = num.top();
        num.pop();
        ll num1 = num.top();
        num.pop();
        char symbol = sym.top();
        sym.pop();
        num.push(calc(num1, num2, symbol));
    }
    return num.top();
}
int main() {
    string s;
    cin >> s;
    cout << calc(s) << endl;
}

//-----

#include <bits/stdc++.h>
using namespace std;

int char_list[99] = {32, 39, 45, 33, 34, 35, 36, 37, 38, 40, 41, 42, 44, 46, 47, 58, 59, 63, 64, 91, 92, 10, 9, 93, 94, 95, 96, 123, 124, 125, 126, 43, 60, 61, 62, 215, 247, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97, 65, 98, 66, 99, 67, 100, 68, 101, 69, 102, 70, 103, 71, 104, 72, 105, 73, 106, 74, 107, 75, 108, 76, 109, 77, 110, 78, 111, 79, 112, 80, 113, 81, 114, 82, 115, 83, 116, 84, 117, 85, 118, 86, 119, 87, 120, 88, 121, 89, 122, 90};

const int maxn = 1e5 + 7;
const int mod = 1e5 + 3;
struct Node {
    int key, val;
    Node(int k = 0, int v = 0) : key(k), val(v) {}
};
Node myHash[maxn];

void add(int key, int val) {
    int t = key;
    key = key % mod;
    while (true) {
        if (!myHash[key].key) {
            myHash[key].key = key;
            myHash[key].val = val;
            return;
        }
        if (myHash[key].key != t) {
            key = (key + 1) % maxn;
        } else
            return;
    }
}
int query(int x) {
    int t = x;
    x = x % mod;
    while (true) {
        if (!myHash[x].key) return 0;
        if (myHash[x].key != t) {
            x = (x + 1) % maxn;
        } else {
            return myHash[x].val;
        }
    }
}

int main() {
    for (int i = 0; i < 99; ++i) {
        add(char_list[i], i + 1);
    }
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ',') s[i] = ' ';
    }
    int n;
    stringstream ss(s);
    int i = 0;
    while (ss >> n) {
        if (i++ == 0) {
            cout << query(n);
        } else {
            cout << ',' << query(n);
        }
    }
}

/*
class Solution1 {
   public:
    vector<int> print(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        if (n == 0) return ans;
        int m = matrix[0].size();
        int start = 0;
        while (start * 2 < n && start * 2 < m) {
            int ex = m - start - 1;
            int ey = n - start - 1;
            for (int i = start; i <= ex; ++i) {
                ans.push_back(matrix[start][i]);
            }

            for (int i = start + 1; i <= ey; ++i) {
                ans.push_back(matrix[i][ex]);
            }

            for (int i = ex - 1; i >= start; --i) {
                ans.push_back(matrix[ey][i]);
            }

            for (int i = ey - 1; i >= start + 1; --i) {
                ans.push_back(matrix[i][start]);
            }
            ++start;
        }
        return ans;
    }
    void solve() {
        vector<vector<int>> matrix = {{1, 2, 3, 4},
                                      {5, 6, 7, 8},
                                      {9, 10, 11, 12},
                                      {13, 14, 15, 16},
                                      {17, 18, 19, 20}};
        vector<int> ans = print(matrix);
        for (int i = 0; i < ans.size(); ++i) {
            if (i == 0)
                cout << ans[i];
            else
                cout << ", " << ans[i];
        }
        cout << endl;
    }
};

class Solution2 {
   public:
    void solve() {
        vector<int> arr = {4, 1, 4, 3, 12};
        int l = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] != 0) {
                swap(arr[i], arr[l++]);
            }
        }
        for_each(arr.begin(), arr.end(), [](int x) { cout << x << " "; });
        cout << endl;
    }
};

class Solution3 {
   public:
    void solve() {
        vector<int> arr1 = {1, 4, 7, 9};
        vector<int> arr2 = {5, 7, 11, 14};
        vector<int> ans;
        dfs(arr1, arr2, 0, arr1.size() - 1, ans);
        for_each(ans.begin(), ans.end(), [](int x) { cout << x << " "; });
        cout << endl;
    }
    // 闭区间
    void dfs(vector<int>& arr1, vector<int>& arr2, int l, int r, vector<int>& ans) {
        if (l > r) return;
        int mid = (l + r) >> 1;
        auto p = lower_bound(arr2.begin(), arr2.end(), arr1[mid]);
        if (p != arr2.end()) {
            cout << "p:" << *p << endl;
        }
        if (p == arr2.begin() && *p > arr1[mid]) {
            for_each(arr1.begin() + l, arr1.begin() + mid + 1, [&ans](int x) {
                ans.push_back(x);
            });
            dfs(arr1, arr2, mid + 1, r, ans);

        } else if (p == arr2.end()) {
            ans.push_back(arr1[mid]);
            dfs(arr1, arr2, l, r - 1, ans);
        } else {
            if (*p != arr1[mid]) {
                ans.push_back(arr1[mid]);
            }
            dfs(arr1, arr2, l, mid - 1, ans);
            dfs(arr1, arr2, mid + 1, r, ans);
        }
    }
};

class Solution4 {
   public:
    void solve() {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
        // vector<int> arr = {3, 5, 4, 2, 1, 6, 8, 7};
        if (arr.size() == 0) return;
        vector<int> vis(arr.size());
        vector<int> ans{};
        int maxn = arr.front();
        for_each(arr.begin() + 1, arr.end(), [&](int x) {
            if (x > maxn) {
                ++vis[x];
                maxn = x;
            }
        });
        int minn = arr.back();
        for_each(arr.rbegin() + 1, arr.rend(), [&](int x) {
            if (x < minn) {
                ++vis[x];
                minn = x;
            }
        });
        for_each(arr.begin(), arr.end(), [&](int x) {
            if (vis[x] == 2) ans.push_back(x);
        });
        for_each(ans.begin(), ans.end(), [&](int x) {
            cout << x << " ";
        });
        cout << endl;
    }
};
*/
