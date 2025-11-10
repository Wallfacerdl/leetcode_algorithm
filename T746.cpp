/*
// 746. 使用最小花费爬楼梯 # 动态规划
//取f(n) 表示从第n阶爬上去所需要的费用
//有递推公式：f(n)=min(f(n-1),f(n-2)) +cost(n)
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 1) return cost[1];
        else if (n == 2) return min(cost[0],cost[1]);
        else
        {
            int x = cost[n-1],y= cost[n-2];
            for (int i = n-1 ;i>=2;i--)
            {
                int tmp = y;
                y = min(x,y) + cost[i-2];
                x = tmp;
            }
            return min(x,y);
        }

    }
};