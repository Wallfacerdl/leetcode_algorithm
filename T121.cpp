// 买股票的最佳时机 # 贪心算法 # 动态规划 # 双指针

#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int in = 0, out = 0;
        int maxProfit = 0;
        for (int cur = 1; cur < size(prices); cur++)
        {

            if (prices[cur] < prices[in])
            {
                in = cur;
                if (out < in)
                {
                    out = in;
                }
            }
            if (prices[cur] > prices[out])
            {
                out = cur;
            }
            maxProfit = max(maxProfit, prices[out] - prices[in]);
        }
        cout << in << " " << out << endl;
        return maxProfit;
    }
};
// ​maxProfit变量独立于 in和 out指针的实时变化。它是一个“守护者”，只增不减地
//  记录遍历过程中遇到的最大利润值。即使 in和 out指针因为遇到新低点而被重置，
//  maxProfit已经保存了之前计算出的更高利润。后续计算出的利润如果更大则更新，否则
//  maxProfit保持不变。