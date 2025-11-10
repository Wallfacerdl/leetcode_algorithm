/*
137. Single Number II # 哈希表法 # 位运算法
给出数组中只出现过一次的数
*/
#include <vector>
#include <unordered_map>
using namespace std;
#include <iostream>

// 哈希表法
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> hmap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!hmap[nums[i]]) // 是否存在，不存在则添加
            {
                hmap[nums[i]] = 1;
            }
            else // 若已经存在，
                hmap[nums[i]] += 1;
        }
        unordered_map<int, int>::iterator iter = hmap.begin();
        for (; iter != hmap.end(); iter++)
        {
            if (iter->second == 1)
            {
                return iter->first;
            }
        }
        return 0;
    }
};

// 位运算法
class Solution2
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int total = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                total += ((nums[j] >> i) & 1);
            }
            if (total % 3)
            {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};