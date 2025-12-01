// 排序数组 # 快速排序
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0 || n == 1)
            return nums;
        else
        {
            fastSortArray_helper(nums, 0, n - 1);
            return nums;
        }
    }
    void fastSortArray_helper(vector<int> &nums, int begin, int end)
    {
        int i = begin, j = end;
        if (i >= j)
            return;

        // 生成一个在 [begin, end] 范围内的随机索引
        int randomIndex = begin + rand() % (end - begin + 1);
        // 将随机选择的元素与当前首元素交换
        swap(nums[begin], nums[randomIndex]);
        int select = nums[begin];

        while (i < j)
        {
            while (nums[j] > select)
            {
                j--;
            }
            if (i >= j)
                break;
            swap(nums[j], nums[i]);
            i += 1;
            while (nums[i] < select)
            {
                i++;
            }
            if (i >= j)
                break;
            swap(nums[j], nums[i]);
            j -= 1;
        }
        fastSortArray_helper(nums, begin, i - 1);
        fastSortArray_helper(nums, i + 1, end);
    }
};
// 调试
int main()
{
    Solution s;
    vector<int> nums = {5, 1, 1, 2, 0, 0};
    s.sortArray(nums);
    // 输出
    for (auto num : nums)
    {
        printf("%d ", num);
    }
    return 0;
}