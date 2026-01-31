// 88. 合并两个有序数组 # 双指针+辅助数组 # 逆序添加
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int res[m + n];
        int i = 0, j = 0;
        int index = 0;
        while (i < m || j < n)
        {

            if (i == m) // num1已到终点
            {
                res[index++] = nums2[j++];
            }
            else if (j == n) // nums2已到终点
            {
                res[index++] = nums1[i++];
            }
            if (nums1[i] <= nums2[j])
            {
                res[index++] = nums1[i++];
            }
            else if (nums1[i] > nums2[j])
            {
                res[index++] = nums2[j++];
            }
        }
        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = res[i];
        }
    }
};
class Solution2
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1, p2 = n - 1, end = m + n - 1;
        // 只需处理 nums2 中的元素；nums1 剩余元素已就位
        while (p2 >= 0)
        {
            if (p1 >= 0 && nums1[p1] > nums2[p2])
            {
                nums1[end--] = nums1[p1--];
            }
            else
            {
                nums1[end--] = nums2[p2--];
            }
        }
    }
};
int main()
{
    // [1,2,3,0,0,0]
    Solution2 sol;
    vector<int> x{5, 8, 0, 0, 0, 0, 0};
    vector<int> y{1, 3, 6, 7, 9};
    int x_size = 2;
    int y_size = y.size();
    sol.merge(x, x_size, y, y_size);
    for (int &num : x)
    {
        cout << num << " ";
    }
}