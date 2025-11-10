// 回文链表 # 递归法 # 栈法 # 快慢指针+链表翻转
//
#include <iostream>
#include <stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *tmp = head;
        int length = 1;
        while (tmp->next)
        {
            length += 1;
            tmp = tmp->next;
        }
        if (length == 1)
            return true;
        stack<int> stk;
        tmp = head;
        // cout << "length" <<length<<endl;
        for (int i = 1; i <= length; i++)
        {
            if (i <= length / 2)
            {
                stk.push(tmp->val);
            }
            else
            {
                if (length % 2 == 1 && i == (length / 2 + 1))
                {
                    tmp = tmp->next;
                    continue; // 跳过奇数长度情况下的中间节点
                }
                cout << tmp->val << endl;
                if (stk.top() == tmp->val)
                    stk.pop();
                else
                {
                    return false;
                }
            }
            tmp = tmp->next;
        }
        return stk.empty();
    }
};

// 法2：快慢指针+链表反转
class Solution2
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *quick = head, *slow = head;
        if (head == nullptr)
            return true;
        // 快慢指针确定过一半的位置
        while (quick && quick->next)
        {
            quick = quick->next->next;
            slow = slow->next;
        }
        // 翻转后半部分
        ListNode *reversed_head = nullptr;
        while (slow != nullptr)
        {
            ListNode *nextnode = slow->next;
            slow->next = reversed_head;
            reversed_head = slow;
            slow = nextnode;
        }
        // 比较是否回文
        while (reversed_head)
        {
            if (reversed_head->val != head->val)
                return false;
            reversed_head = reversed_head->next;
            head = head->next;
        }
        return true;
    }
};