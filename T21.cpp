// 合并有序链表
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode start(0, nullptr);
        ListNode *cur = &start;
        ListNode *p = list1;
        ListNode *q = list2;
        while (p && q)
        {
            if (p->val < q->val)
            {
                cur->next = p;
                p = p->next;
            }
            else
            {
                cur->next = q;
                q = q->next;
            }

            cur = cur->next;
        }
        cur->next = p ? p : q;
        return start.next;
    }
};