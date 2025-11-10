/*

*/
// 141. 环形链表 给定一个链表，判断链表中是否有环。
// # 链表 # 哈希表（不建立映射关系，只存储访问过的节点这样便于查找）
// # 快慢指针（双指针）

#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen; // 创建一个无序集合来记录访问过的节点地址
        while (head != nullptr) {     // 遍历链表
            if (seen.count(head)) {   // 如果当前节点地址已在集合中，发现环
                return true;
            }
            seen.insert(head);        // 否则，将当前节点地址加入集合
            head = head->next;        // 移动到下一个节点
        }
        return false; // 成功遍历到链表末尾，说明无环
    }
};

// 法2：# 快慢指针 # 龟兔赛跑算法
class Solution2
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;
        else if (head->next == NULL)
            return false;
        // if ()  ListNode *fast = head->next;
        // else {cout <<"只有一个" << endl;return false;}
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast)
        {
            if (fast->next)
            {
                if (slow->next && fast->next->next)
                {
                    slow = slow->next;
                    fast = fast->next->next;
                }
                else
                {
                    cout << "wrong" << endl;
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};