class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        # print(stack[-1].val)
        length = 1
        # 先统计长度
        while head.next:
            length += 1
            head = head.next
        if length == 1:
            return True

        # lst = [head.val]
        # while head.next:
        #     lst.append(head.val)
        #     head = head.next
        #     length += 1
        # return lst == lst[::-1]

        # while head.next:
        #     if len(stack) == 0:
        #         stack = [head]
        #     flag = False
        #     length += 1
        #     head = head.next
        #     # print(head.val)
        #     cankao = stack[-1]
        #     if cankao.val == head.val:
        #         stack = stack[:-1]  # 如果刚好与上一个相同，就把上一个弹出
        #     else:  # 如果不同，分类讨论

        #         # 获取当前栈的长度
        #         if len(stack) == 1:  # 如果只有一个节点，直接入栈
        #             stack.append(head)
        #             continue
        #         cankao = stack[-2]  # 取倒数第二个进行比较
        #         if (
        #             not xiaodiao_flag and cankao.val != head.val
        #         ):  # 如果还是不相等，证明不是回文，入栈
        #             stack.append(head)
        #         else:  # 如果相等，就把倒数第二个弹出，然后把倒数第一个和当前的合并
        #             stack = stack[:-2] + [stack[-1]]
        #             flag = True
        # if length % 2 == 0:  # 偶数个节点，理应全部弹出
        #     return not bool(stack)
        # else:  # 奇数个节点，只能剩下中间的一个
        #     if length == 1:
        #         return True
        #     else:
        #         return len(stack) == 1 and flag == True
        # # print(stack)


print(Solution().isPalindrome(ListNode(1, ListNode(0, ListNode(0)))))  # False
print(Solution().isPalindrome(ListNode(1, ListNode(1, ListNode(2, ListNode(1))))))
print(
    Solution().isPalindrome(
        ListNode(1, ListNode(2, ListNode(3, ListNode(2, ListNode(1)))))
    )
)  # 12321 是回文吗？——是
print(
    Solution().isPalindrome(
        ListNode(1, ListNode(2, ListNode(3, ListNode(3, ListNode(1)))))
    )
)  # True
print(
    Solution().isPalindrome(
        ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(1)))))
    )
)  # False
print(
    Solution().isPalindrome(
        ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    )
)  # False
