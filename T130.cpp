// 130:相交链表 # 迭代法 # 双指针法
//
#include <stdio.h>
#include <iostream>

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p = headA;
        ListNode *q = headB;
        int count = 0;
        while (p && q)
        {
            count++;
            p = p->next;
            q = q->next;
        }
        int count_a = count;
        int count_b = count;
        while (p)
        {
            p = p->next;
            count_a++;
        }
        while (q)
        {
            q = q->next;
            count_b++;
        }
        p = headA;
        q = headB;
        while (count_a != count_b)
        {
            if (count_a > count_b)
            {
                p = p->next;
                count_a--;
            }
            else if (count_a < count_b)
            {
                q = q->next;
                count_b--;
            }
        }
        cout << p->val << q->val << endl;
        int res;
        while (p && q)
        {
            if (p == q)
            {
                return p;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
        return NULL;
    }
};

// 法2：哈希集合
#include <unordered_set>
class Solution2
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p = headA;
        unordered_set<ListNode *> visited;
        int i = 0;
        while (p)
        {
            visited.insert(p);
            i++;
            p = p->next;
        }
        p = headB;
        while (p)
        {
            if (visited.count(p))
                return p;
            p = p->next;
        }
        return NULL;
    }
};
// 法3：双指针法
class Solution3 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {return NULL;}
        else
        {
            ListNode *p = headA,*q = headB;
            while(true)
            {
                if (p == q) {return q;}
                if (!p) p = headB;
                else {p = p->next;}
                if (!q) q = headA;
                else {q = q->next;}
            }
            return NULL;
        }
    }
};
//两个链表不相交
// 链表 headA 和 headB 的长度分别是 m 和 n。考虑当 m=n 和 m
// 
// =n 时，两个指针分别会如何移动：

// 如果 m=n，则两个指针会同时到达两个链表的尾节点，然后同时变成空值 null，此时返回 null；

// 如果 m
// 
// =n，则由于两个链表没有公共节点，两个指针也不会同时到达两个链表的尾节点，因此两个指针都会遍历完两个链表，在指针 pA 移动了 m+n 次、指针 pB 移动了 n+m 次之后，两个指针会同时变成空值 null，此时返回 null。

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/intersection-of-two-linked-lists/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。