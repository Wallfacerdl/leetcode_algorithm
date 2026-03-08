// T62:不同路径 # 动态规划 # 组合数
#include <iostream>
using namespace std;
#include <vector>

// 法一：组合数
class Solution1
{
public:
    int uniquePaths(int m, int n)
    {
        m = m - 1; // 组合数上标
        n = n - 1;
        int total = m + n;
        long long ans = 1;
        for (int y = 1, x = n + 1; y <= m; y++, x++)
        {
            ans = ans * x / y;
        }
        return ans;
    }
};
// 法二： 动态规划（未优化空间）
class Solution2
{
public:
    int uniquePaths(int m, int n)
    {
        // 初始化
        vector<vector<int>> mat(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
            }
        }
        return mat[m - 1][n - 1];
    }
};
// 法三：优化空间后的动态规划(空间复杂度O(2N))
class Solution3
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> lastrow(n, 1);
        for (int j = 1; j < m; j++)
        {
            vector<int> currow(n, 1);
            for (int i = 1; i < n; i++)
            {
                currow[i] = currow[i - 1] + lastrow[i];
            }
            lastrow = currow;
        }
        return lastrow.back(); // C++ 中获取最后一个元素用 .back() 或 lastrow[n - 1]
    }
};
// 法四：用一个行来存储
class Solution4
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> cur_row(n, 1);
        for (int j = 1; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                cur_row[i] = cur_row[i - 1] + cur_row[i];
            }
        }
        return cur_row.back();
    }
};

int main()
{
    // 法一
    // Solution1 sol1;
    // cout << sol1.uniquePaths(3, 7) << endl;
    // Solution2 sol2;
    // cout << sol2.uniquePaths(3, 7) << endl;
    // Solution3 sol3;
    // cout << sol3.uniquePaths(3, 7) << endl;
    Solution4 sol4;
    cout << "第四种方法: " << sol4.uniquePaths(3, 7) << endl;
}