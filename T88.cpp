// 88. 合并两个有序数组
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (nums2.empty())
            return;
        int i = 0, j = 0;
        int offset = 0;
        while (i < m)
        {
            if (nums1[i] <= nums2[j])
            {
                i++;
                continue;
            }
            while (nums1[i] > nums2[j] && i < m)
            {
                nums1[m + offset] = nums1[i];
                nums1[i] = nums2[j];
                offset++;
                j++;
                i++;
            }
        }
        while (offset < n)
        {
            nums1[m + offset] = nums2[j];
            offset++;
            j++;
        }
    }
};
int main()
{
    // [1,2,3,0,0,0]
    Solution sol;
    vector<int> x{2, 0};
    vector<int> y{1};
    int x_size = 1;
    int y_size = y.size();
    sol.merge(x, x_size, y, y_size);
    for (int &num : x)
    {
        cout << num << " ";
    }
}