// 697.数组的度 # 自定义哈希
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    struct NumberInfo {
        int frequency;    // 出现次数
        int startIndex;   // 首次出现位置
        int endIndex;     // 末次出现位置
    };

public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.empty()) return 0; // 处理空数组情况

        unordered_map<int, NumberInfo> numInfoMap;
        int maxDegree = 0;
        vector<int> candidateNums; // 存储所有出现次数等于maxDegree的数字
        int minLength = INT_MAX;   // 初始化为最大整数，避免依赖数组长度

        for (int i = 0; i < nums.size(); ++i) {
            int currentNum = nums[i];
            
            if (numInfoMap.find(currentNum) == numInfoMap.end()) {
                // 数字第一次出现，初始化记录
                numInfoMap[currentNum] = {1, i, i};
            } else {
                // 更新已存在数字的频次和结束位置
                numInfoMap[currentNum].frequency++;
                numInfoMap[currentNum].endIndex = i;
            }

            int currentFreq = numInfoMap[currentNum].frequency;
            
            if (currentFreq > maxDegree) {
                // 发现新的最大度，更新候选集
                maxDegree = currentFreq;
                candidateNums.clear();
                candidateNums.push_back(currentNum);
            } else if (currentFreq == maxDegree) {
                // 当前数字频次等于最大度，加入候选集
                candidateNums.push_back(currentNum);
            }
        }

        // 计算所有候选数字的最短子数组长度
        for (int num : candidateNums) {
            int currentLength = numInfoMap[num].endIndex - numInfoMap[num].startIndex + 1;
            minLength = min(minLength, currentLength);
        }

        return minLength;
    }
};
