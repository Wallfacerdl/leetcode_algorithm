// 翻转链表 # 迭代法 # 递归法
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *tmp = head;
        if (!(tmp && tmp->next))
        {
            return tmp;
        }
        ListNode *node = reverseList(tmp->next);
        head->next->next = head;
        head->next = nullptr;
        cout << node->val << endl;
        return node;
    }
};
// 法2：迭代法
class Solution2
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *res = new ListNode();
        while (head)
        {
            ListNode *nextNode = head->next; // 保存下一个节点
            head->next = res->next;          // 当前节点指向新链表头
            res->next = head;                // 更新链表头为当前头结点
            head = nextNode;                 // 移动到下一个节点
        }
        return res->next;
    }
};

// 法3：迭代法-优化版（三指针法）
class Solution3
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *newHead = nullptr; // 改用创建一个指针（不需要创建空的头结点），此时就没有next属性了，所以res->next要直接替换为newHead,换句话说，就是直接将指针作为
        while (head)
        {
            ListNode *nextNode = head->next; // 保存下一个节点
            head->next = newHead;            // 当前节点指向新链表头
            newHead = head;                  // 更新链表头为当前头结点
            head = nextNode;                 // 移动到下一个节点
        }
        return newHead;
    }
};

// 测试
int main()
{
    Solution2 sol;
    // 创建测试链表 1->2->3->4->5
    ListNode *n5 = new ListNode(5);
    ListNode *n4 = new ListNode(4, n5);
    ListNode *n3 = new ListNode(3, n4);
    ListNode *n2 = new ListNode(2, n3);
    ListNode *n1 = new ListNode(1, n2);
    ListNode *res = sol.reverseList(n1);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
