// 11.盛最多水的容器 #双指针法-对撞指针（首尾指针）
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0,len = height.size();
        int left_p=0,right_p = len - 1;
        while(left_p<right_p)
        {
            int h = min(height[left_p],height[right_p]);
            int volume = (right_p - left_p) * h;
            max = std::max(max,volume);
            if (height[left_p] > height[right_p])
            {right_p -= 1;}
            else{left_p += 1;}

        }
        return max;
    }
};
