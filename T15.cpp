// T15：三数之和 # 三指针（核心在于去重）
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0;i<n;i++){
            // cout << "i " << i << endl;
            if (i > 0 && nums[i-1] == nums[i]) continue;
            int sum = - nums[i];
            int start = i + 1,end = n - 1;
            while(start < end)
            {
                if (nums[start] + nums[end] < sum){
                    start ++;
                    while(nums[start] == nums[start - 1]){
                        start++;
                        if (start>=end){
                            break;
                        }
                    }
                }
                else if (nums[start] + nums[end] > sum ){
                    end --;
                    while(nums[end] == nums[end + 1]){
                        end --;
                        if (end <= i ) break;
                    }
                }
                else{
                    // -4 -1 -1 0 1 2
                    vector <int> v0 = {nums[i],nums[start],nums[end]};
                    result.push_back(v0);
                    // cout << "内部"<< start << " " << end << endl;
                    start ++;end --;
                    while(nums[start] == nums[start - 1]) {start++;if(start >= n) break;}
                    while(nums[end] == nums[end + 1]) {end --;if(end <= i) break;}
                }
            }
        }
        return result;
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