/*
T2:两数之和 # 链表操作
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int jinwei = 0;
        ListNode *begin_l1 = l1;
        while (l1 && l2)
        {
            int yushu = (l1->val + l2->val + jinwei) % 10;
            jinwei = (l1->val + l2->val + jinwei) / 10;
            l1->val = yushu;
            if (l1->next && l2->next)
            {
                l1 = l1->next;
                l2 = l2->next;
            }
            else
                break;
        }
        while (l1->next)
        {
            l1 = l1->next;
            int yushu = (l1->val + jinwei) % 10;
            jinwei = (l1->val + jinwei) / 10;
            l1->val = yushu;
            if (!l1->next)
                break;
        }
        while (l2->next)
        {
            l2 = l2->next;
            int yushu = (l2->val + jinwei) % 10;
            jinwei = (l2->val + jinwei) / 10;
            l2->val = yushu;
            l1->next = l2;
            l1 = l1->next;
        }
        if (jinwei == 1)
        {
            ListNode *n = new ListNode(1);
            l1->next = n;
            return begin_l1;
        }
        return begin_l1;
    }
};