#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x, ListNode *nxt = nullptr) : val(x), next(nxt) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> lst;
        while (head)
        {
            lst.push_back(head->val);
            head = head->next;
        }
        int n = lst.size();
        for (int i = 0; i < n / 2; ++i)
        {
            if (lst[i] != lst[n - 1 - i])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))))) << endl;
    cout << sol.isPalindrome(new ListNode(1, new ListNode(0, new ListNode(0)))) << endl;
    cout << sol.isPalindrome(new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(1))))) << endl;
    cout << sol.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(1)))))) << endl;
    cout << sol.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(1)))))) << endl;
    cout << sol.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(1)))))) << endl;
    cout << sol.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))))) << endl;
    return 0;
}