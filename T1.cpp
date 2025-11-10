// 1.两数之和 # 法1：排序+双指针法 法2：哈希表法（推荐）
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int len = nums.size();
        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());
        int i = 0, j = len - 1;
        while (i < j)
        {
            if (sorted_nums[j] + sorted_nums[i] == target)
            {
                // 在原始数组中找到第一个值的索引
                auto iter1 = find(nums.begin(), nums.end(), sorted_nums[i]);
                int index1 = iter1 - nums.begin();
                // 关键修正：从 index1 之后开始寻找第二个值，确保不是同一个元素
                auto iter2 = find(nums.begin() + index1 + 1, nums.end(), sorted_nums[j]);
                // 如果没找到，说明两个值可能相同，且第一个值之后没有第二个值，尝试从开头找第二个值（但索引不同）
                if (iter2 == nums.end())
                {
                    iter2 = find(nums.begin(), nums.end(), sorted_nums[j]);
                    // 如果 iter2 指向了 index1，则继续往后找
                    while (iter2 != nums.end() && (iter2 - nums.begin()) == index1)
                    {
                        iter2 = find(iter2 + 1, nums.end(), sorted_nums[j]);
                    }
                }
                int index2 = iter2 - nums.begin();
                return {index1, index2};
                // return vector<int>{ans1, ans2};
            }
            else if (sorted_nums[i] + sorted_nums[j] < target)
                i += 1;
            else
                j -= 1;
        }
        return vector<int>{-1, -1};
    }
};
/* // 法2：哈希表法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hmap;
        int i = 0,len = nums.size();
        for (int num:nums)
        {
            hmap[num] = i;
            i+= 1;
        }
        for (int i = 0;i<len;i++)
        {
            // 使用 find 方法进行判断，避免自动创建键
            auto it = hmap.find(target-nums[i]);
            if ((it != hmap.end()&& it->second != i)) {return {i,it ->second};}
        }
        return {-1,-1};
    }
};
*/

/* 法2改进：边遍历边存储，减少一次遍历
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hmap;
        int i = 0,len = nums.size();
        for (int num:nums)
        {
            int complement = target - num;
            auto it = hmap.find(complement);
            if (it != hmap.end()) {return {i,it->second};}
            else //尚未找到
            {hmap[num] = i;i+=1;}
    }
    return {-1,-1};
}
};
*/
int main()
{
    Solution sol;
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> result = sol.twoSum(nums, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}