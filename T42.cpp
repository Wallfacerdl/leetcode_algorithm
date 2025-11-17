// 接雨水
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0, pos = 0, left_border = 0;
        return trap_helper(height, pos, height[pos], res);
    }
    int trap_helper(vector<int> &height, int &cur_pos, int left_height, bool in = false)
    {
        int start = 0, length = 0, width = 0, res = 0;
        while (cur_pos < height.size())
        {
            if (height[cur_pos] > height[cur_pos + 1])
            {
                cur_pos++;
                width++;
                res += trap_helper(height, cur_pos, height[cur_pos - 1], true);
                width = 0;
            }
            else if (height[cur_pos] < height[cur_pos + 1]) // 需要加入计算，计算完后退出
            {
                int right_height = height[cur_pos + 1];
                int cur_height = height[cur_pos];
                cur_pos++;
                width++;
                int real_height = std::min(left_height, right_height);
                res += ((real_height - cur_height) * width); // 高度差;
                if (in)
                    return res;
                width = 0;
            }
            else // 相等情况
            {
                res += (std::min(left_height, height[cur_pos + 1]) - height[cur_pos]);
                cur_pos++;
            }
        }
        return res;
    }
};

// 调试：[0,1,0,2,1,0,1,3,2,1,2,1]
int main()
{
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution sol;
    int ans = sol.trap(v);
}