// 在排序数组中查找元素的第一个和最后一个位置
// 二分法
// 两次二分法先后确定两个端点即可
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int len = nums.size();
        int left = 0, right = len - 1;
        int first = -1, last = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                first = mid;
                right = mid - 1; // 此时循环仍在继续，向左遍历找寻真正的first所在处
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        // 同样的方法找寻最后一个等于target所在处
        // 首先先将left和right归位
        left = 0;
        right = len - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                last = mid;
                left = mid + 1; // 向右继续遍历
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return {first, last};
    }
};
// 测试
int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution sol;
    vector<int> ans = sol.searchRange(nums, 8);
    for (int x : ans)
    {
        cout << x << " ";
    }
}
