/*
T70:爬楼梯问题 # 动态规划 # 斐波那契 # 递推公式
*/

class Solution {
public:
    int climbStairs(int n) {
        int x = 1,y = 1;
        for (int i = 1;i<n;i++)
        {
            int tmp_x = x;
            x = y;
            y = tmp_x+y;
        }
        return y;
    }
};