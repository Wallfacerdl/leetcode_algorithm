// 35.搜索插入位置 # 二分查找法 # 边界条件处理
//  给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//  如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int begin = 0, end = size(nums) - 1, mid = 0;
        // 处理特殊情况
        if (target <= nums[begin])
            return 0;
        else if (target == nums[end])
            return end;
        else if (target > nums[end])
            return end + 1;
        else
        {
            while (end > begin)
            {
                mid = (begin + end) / 2;
                if (nums[mid] < target)
                {
                    begin = mid + 1;
                }
                else if (nums[mid] > target)
                {
                    end = mid - 1;
                }
                else
                {
                    return mid;
                }
            }
            cout << "已经收敛" << begin << mid << end << endl;
            // 此时end == begin
            return target <= nums[end] ? end : end + 1;
        }
    }
};