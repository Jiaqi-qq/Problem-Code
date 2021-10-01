#include <assert.h>
#include <bits/stdc++.h>
using namespace std;

void sw_w32(void *a, void *b, int n) {
    assert(sizeof(a) >= n && sizeof(a) >= n && n % 4 == 0);
    do { // 从第n个字节位置向前，每次4个字节，交换a、b内容
        // 从a起始地址开始，偏移(n-4)个字节，将4个字节内容读取为整型，下同理
        int t = *(int *)(a + (n -= 4));
        *(int *)(a + n) = *(int *)(b + n);
        *(int *)(b + n) = t;
    } while (n); // 每次n-=4进入下次循环
}

int mystrncasecmp(char *src, char *dst, size_t size) {
    cout << strlen(src) << endl;
    assert(src && dst);
    for (size_t i = 0; i < size; ++i) {
        if (tolower(src[i]) == tolower(dst[i]))
            continue;
        if (tolower(src[i]) > tolower(dst[i]))
            return 2;
        else
            return -2;
    }
    return 0;
}

int main() {
    cout << mystrncasecmp("12345", "456", 3) << endl;

    cout << endl;
    int *x = new int[2]{1, 2};
	int *y = new int[2]{3, 4};
    sw_w32(x, y, 1);
    cout << x[0] << endl;
    cout << y[0] << endl;
}