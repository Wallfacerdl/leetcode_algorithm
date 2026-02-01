
// 删除链表的倒数第N个节点
// 方法：计算链表长度，然后找到正数第L-N+1个节点并删除
// 链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == nullptr)
            return nullptr;
        int cur = 1;
        int len = 1;
        ListNode *p = head;
        while (p->next != nullptr)
        {
            len++;
            p = p->next;
        }
        cout << len;
        if (len == n)
            return head->next;
        p = head;
        while (cur < len - n)
        {
            p = p->next;
            cur++;
        }
        ListNode *tmp = p->next;
        p->next = tmp->next;
        return head;
    }
};
// 测试
int main()
{
    ListNode *l1 = new ListNode(1, new ListNode(2,
                                                new ListNode(3,
                                                             new ListNode(4,
                                                                          new ListNode(5)))));
    Solution sol;
    ListNode *res = sol.removeNthFromEnd(l1, 2);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
}