/*
T202:快乐数
编写一个算法来判断一个数 n 是不是快乐数。
*/

#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

int get_sum(int n);

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> s;
        while (1)
        {
            // cout << n <<endl;
            // 最后将变成10/100/1000这样的
            if (log10(n) == int(log10(n)))
            {
                return true;
            }
            else
            {
                n = get_sum(n);
                if (!s.count(n))
                {
                    s.insert(n);
                }
                else
                    return false;
            }
        }
    }
};
int get_sum(int n)
{
    int sum = 0;
    for (int i = 0;; i++)
    {
        sum += pow(n % 10, 2);
        n = n / 10;
        if (n == 0)
            break;
    }
    return sum;
}

int main()
{
    Solution sol;
    cout << sol.isHappy(4) << endl;
    cout << sol.isHappy(2) << endl;
    cout << sol.isHappy(7) << endl;
    cout << sol.isHappy(1) << endl;
    return 0;
}