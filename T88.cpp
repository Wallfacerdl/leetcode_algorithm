// 88. 合并两个有序数组
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = 0, j = 0;
        int offset = 0;
        while (offset < n)
        {
            if (nums1[i] < nums2[j])
            {
                i++;
                continue;
            }
            else if (nums1[i] > nums2[j])
            {
                nums1[m + offset] = nums1[i];
                nums1[i] = nums2[j];
                offset++;
                j++;
                i++;
            }
        }
    }
};
int main()
{
    // [1,2,3,0,0,0]
}