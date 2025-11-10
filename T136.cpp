/*
T136:找出只出现一次的数字 # 位运算 # 异或
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int num : nums)
        {
            ans ^= num;
        }
        return ans;
    }
};