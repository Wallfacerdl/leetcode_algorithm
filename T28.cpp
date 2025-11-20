// 找到字符串中第一个匹配项的下标
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        vector<int> next;
        next = get_next(needle);
    }
    vector<int> get_next(string needle)
    {
        int i = 1, len = needle.size(), j = 0;
        vector<int> next(0, len + 1);
        while (i < len)
        {
            if (needle[i] == needle[j])
            {
                next[i] += 1;
                j++;
                i++;
            }
            else
            {
                next[i] = 0;
                i++;
            }
        }
        return next;
    }
};

// 测试