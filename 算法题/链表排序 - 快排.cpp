#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v, ListNode *nex = nullptr) : val(v), next(nex){};
};
class Solution {
   public:
    ListNode *quickSortList(ListNode *head) {  //快排
        if (head == NULL || head->next == NULL) return head;
        ListNode tmpHead(0, head);
        qsortList(&tmpHead, head, NULL);
        return tmpHead.next;
    }
    void qsortList(ListNode *headPre, ListNode *head, ListNode *tail) {
        //链表范围是[low, high)
        if (head != tail && head->next != tail) {
            ListNode *mid = partitionList(headPre, head, tail);  // 注意这里head可能不再指向链表头了
            qsortList(headPre, headPre->next, mid);
            qsortList(mid, mid->next, tail);
        }
    }
    ListNode *partitionList(ListNode *lowPre, ListNode *low, ListNode *high) {
        //链表范围是[low, high)
        int key = low->val;
        ListNode node1(0), node2(0);  //比key小的链的头结点，比key大的链的头结点
        ListNode *little = &node1, *big = &node2;
        for (ListNode *i = low->next; i != high; i = i->next)
            if (i->val < key) {
                little->next = i;
                little = i;
            } else {
                big->next = i;
                big = i;
            }
        big->next = high;  //保证子链表[low,high)和后面的部分连接
        little->next = low;
        low->next = node2.next;
        lowPre->next = node1.next;  //为了保证子链表[low,high)和前面的部分连接
        return low;
    }
};