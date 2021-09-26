#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getGrade(char c) { //返回优先级
    switch (c) {
    case '+':
        return 1;
    case 'x':
        return 2;
    case '@':
        return 3;
    default:
        return -1;
    }
}

ll calc(ll a, ll b, char sym) {
    switch (sym) {
    case '+':
        printf("%lld%c%lld=%lld\n", a, '+', b, a + b);
        return a + b;
    case 'x':
        printf("%lld%c%lld=%lld\n", a, 'x', b, a * b);
        return a * b;
    case '@':
        printf("%lld%c%lld=%lld\n", a, '@', b, a | (a + b));
        return a | (a + b);
    default:
        return -1;
    }
}

long long calc(string s) {
    //每次进栈两个
    size_t i = 0;
    stack<ll> num;
    stack<char> sym;

    while (i < s.size()) {
        //数字字符转int放入num
        string nums = "";
        while (isdigit(s[i]))
            nums += s[i++];
        num.push(stoll(nums));

        if (i == s.size())
            break; //读取完

        //运算符放入sym前进行判断，看是否优先级 > 当前栈顶
        char symb = s[i++];
        if (sym.empty()) {
            sym.push(symb);
        } else {
            //大于就放入
            if (getGrade(symb) > getGrade(sym.top())) {
                sym.push(symb);
            }
            //小于等于就取出两数，取一个sym字符进行运算，再放回数字栈中，循环判断字符优先级
            else {
                while (getGrade(symb) <= getGrade(sym.top())) {
                    ll num2 = num.top();
                    num.pop();
                    ll num1 = num.top();
                    num.pop();
                    char symbol = sym.top();
                    sym.pop();
                    num.push(calc(num1, num2, symbol));
                    if (sym.empty())
                        break;
                }
                sym.push(symb);
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