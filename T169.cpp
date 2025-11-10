// T169:找出出现次数大于n/2的元素 # 摩尔投票法 # 哈希表法
// 代码的核心要点在于：若数组的前 a 个数字的 票数和 =0 ，则
// 数组剩余 (n−a) 个数字的 票数和一定仍 >0 ，即后 (n−a) 个数字的 众数仍为 x
#include <vector>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int member = nums[0];
        int count = 0;
        for (int num : nums)
        {
            if (num == member)
            {
                count++;
            }
            else
            {
                count--;
            }
            if (count < 0)
            {
                member = num;
                count = 1;
            }
        }
        return member;
    }
};
// 深层的思考：编程思想
// 编程习惯——在执行状态变化后立即判断策略执行——是非常有价值且
// 实用的设计思维！这种风格在软件开发中很常见，尤其适合处理状态驱动或事件驱动的逻辑。
// 1. ​实用风格 ≈ 观察者模式（Observer Pattern）的简化版​
// ​状态变化​ 作为事件，​立即触发的判断逻辑​ 如同监听器（Listener）。
// 优势：​高内聚，将状态变更与响应策略绑定在同一代码块。
// 适用场景：需要快速响应的状态机（如你的投票法）、UI 事件处理。

// 2. ​标准风格 ≈ 状态模式（State Pattern）的雏形​
// 将 count == 0视为一个独立状态，迁移到新状态时执行动作。
// 优势：​易于扩展新状态​（如添加 count > threshold的中间状态）。
// 适用场景：复杂状态机（如订单流程、游戏角色行为）
// 总结：
#include <unordered_map>
class Solution2
{
public:
    int majorityElement(vector<int> &nums)
    {
        int max = size(nums) / 2;

        // cout << max <<endl;
        unordered_map<int, int> hmap;
        for (int num : nums)
        {
            hmap[num]++;
            if (hmap[num] > max)
            {
                return num;
            }
        }
        return nums[0];
    }
};
