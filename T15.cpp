// T15：三数之和
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int len = size(nums);
        for (int i = 0; i < len; i++)
        {
            int rest_sum = -1 * nums[i];
            unordered_map<int, int> hmap;
            unordered_set<int> set;
            for (int j = 0; j < len; j++)
            {
                if (j == i)
                    continue;
                if (hmap.count(nums[j]))
                {
                    int sum = abs(nums[i]) + abs(nums[j]) + abs(rest_sum - nums[j]);
                    if (!set.count(sum))
                    {
                        cout << nums[i] << nums[j] << rest_sum - nums[j] << endl;
                        cout << sum << endl;
                        res.push_back({nums[i], nums[j], rest_sum - nums[j]});
                        set.insert(sum);
                    }
                }
                hmap[rest_sum - nums[j]] = nums[j];
            }
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = sol.threeSum(nums);
    for (auto vec : res)
    {
        for (auto num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}