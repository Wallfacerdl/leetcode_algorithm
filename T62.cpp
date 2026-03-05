// T62:不同路径 # 动态规划 # 组合数


// 法一：组合数
class Solution {
public:
    int uniquePaths(int m, int n) {
        m = m - 1; // 组合数上标
        n = n - 1;
        int total = m + n;
        long long ans = 1;
        for (int y = 1,x = n + 1;y <= m; y++,x++)
        {
            ans = ans * x / y;
        }
        return ans;
    }
};
// 法二： 动态规划
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 初始化
        vector<vector<int>> mat(m, vector<int>(n, 0));
        int i = 0,j = 0;
        int row = i +j;
        while (row <= m+ n - 2)
        {
            row ++;
            cout << row << endl;
            for (int i = row,j = 0;i>=0 && i< n && j >=0 && j <m;i--,j++)
            {
                if (i == 0) mat[i][j] = 1;
                else if (j == 0) mat[i][j] = 1;
                else
                    mat[i][j] = mat[i-1][j] + mat[i][j-1];
            }
        }
        return mat[i][j];

    }
};