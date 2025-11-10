// 55.跳跃游戏 # 动态规划 # 贪心算法

#include <vector>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        // 步骤1: 定义dp数组，大小为n，初始化所有值为false
        vector<bool> dp(n, false);
        // 步骤2: 设置终点条件
        dp[n - 1] = true;
        // 步骤3: 从倒数第二个位置向前遍历到起始位置0
        for (int i = n - 2; i >= 0; i--)
        {
            // 从位置i能跳跃的最大长度是nums[i]
            int max_jump = nums[i];
            // 检查从i能跳到的所有位置j（从i+1到i+max_jump，但不超界）
            if (i + max_jump >= n - 1)
            {
                dp[i] = true; // 可以直接跳到或超过终点
                continue;
            }
        }
        // 步骤4: 返回dp[0]
        return dp[0];
    }
};
// 动态规划优化版（内层循环属于冗余，直接找最远距离即可）
class Solution2
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        // 步骤1: 定义dp数组，大小为n，初始化所有值为false
        vector<bool> dp(n, false);
        // 步骤2: 设置终点条件
        dp[n - 1] = true;
        int max_reach = n - 1;// 标记目前能跳到终点的最近地方
        // 步骤3: 从倒数第二个位置向前遍历到起始位置0
        for (int i = n - 2; i >= 0; i--)
        {
            // 从位置i能跳跃的最大长度是nums[i]
            int max_jump = nums[i];
            // 检查从i能跳到的所有位置j（从i+1到i+max_jump，但不超界）
            if (i + max_jump >= max_reach)
            {
                dp[i] = true; // 可以直接跳到或超过终点
                max_reach = i;
            }
            else
            {
                dp[i] = false;
            }
        }
        for (int i:dp) {cout << i << " ";}
        // 步骤4: 返回dp[0]
        return dp[0];
    }
};

// 贪心算法优化（不再维护dp,节约空间复杂度
class Solution3
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int max_reach = n - 1;// 标记目前能跳到终点的最近地方
        //  从倒数第二个位置向前遍历到起始位置0
        for (int i = n - 2; i >= 0; i--)
        {
            // 从位置i能跳跃的最大长度是nums[i]
            int max_jump = nums[i];
            // 检查从i能跳到的所有位置j（从i+1到i+max_jump，但不超界）
            if (i + max_jump >= max_reach)
            {
                max_reach = i;
            }
        }
        // for (int i:dp) {cout << i << " ";}
        // 步骤4: 返回dp[0]
        return max_reach == 0;
    }
};
int main()
{
    //[2,3,1,1,4]
    Solution2 sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    bool res = sol.canJump(nums);
    return 0;
}