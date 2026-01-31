// 移动元素 # 双指针法
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int tail = n - 1;
        int head = 0;
        while (head <= tail)
        {
            if (nums[head] != val && nums[tail] == val)
            {
                head++;
                tail--;
            }
            else if (nums[head] == val && nums[tail] == val)
            {
                tail--;
            }
            else if (nums[head] != val && nums[tail] != val)
            {
                head++;
            }
            else if (nums[head] == val && nums[tail] != val)
            {
                nums[head] = nums[tail];
                head++;
                tail--;
            }
        }
        return head;
    }
};
int main()
{
    Solution sol;
    vector<int> v1{3, 2, 2, 3};
    cout << sol.removeElement(v1, 3);
}