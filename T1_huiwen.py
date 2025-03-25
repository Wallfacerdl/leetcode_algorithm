class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        # 1.将链表存储起来
        lst = [head.val]
        while head.next:
            lst.append(head.next.val)
            head = head.next
        # 2.判断是否是回文
        print(lst == lst[::-1])
        return lst == lst[::-1]


if __name__ == "__main__":
    Solution().isPalindrome(ListNode(1, ListNode(2, ListNode(2, ListNode(1)))))
    Solution().isPalindrome(ListNode(1, ListNode(0, ListNode(0))))
    Solution().isPalindrome(ListNode(1, ListNode(1, ListNode(2, ListNode(1)))))
    Solution().isPalindrome(
        ListNode(1, ListNode(2, ListNode(3, ListNode(2, ListNode(1)))))
    )
    Solution().isPalindrome(
        ListNode(1, ListNode(2, ListNode(3, ListNode(3, ListNode(1)))))
    )
    Solution().isPalindrome(
        ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(1)))))
    )
    Solution().isPalindrome(
        ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    )
