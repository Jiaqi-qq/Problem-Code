#include <arpa/inet.h>
#include <bits/stdc++.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("usage: %s 域名\n", basename(argv[0]));
        return 1;
    }
    const char *ptrName = argv[1];
    char **pptr;
    hostent *hptr;
    if ((hptr = gethostbyname(ptrName)) == NULL) {
        printf("gethostbyname error for host:%s\n", ptrName);
        return 0; /* 如果调用gethostbyname发生错误，返回1 */
    }

    /* 将主机的规范名打出来 */
    printf("official hostname:%s\n", hptr->h_name);
    /* 主机可能有多个别名，将所有别名分别打出来 */
    for (pptr = hptr->h_aliases; *pptr != NULL; pptr++)
        printf(" alias:%s\n", *pptr);

    /* 根据地址类型，将地址打出来 */
    char str[32];
    switch (hptr->h_addrtype) {
    case AF_INET:
    case AF_INET6:
        pptr = hptr->h_addr_list;
        for (; *pptr != NULL; pptr++) {
            printf(" address:%s\n",
                   inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
        }
        break;
    default:
        printf("unknown address type\n");
        break;
    }
    return 0;
}