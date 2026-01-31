// 赎金信  # 哈希
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<int, int> hmap1;
        unordered_map<int, int> hmap2;
        for (char c : ransomNote)
        {
            hmap1[c - 'a']++;
        }
        for (char c : magazine)
        {
            hmap2[c - 'a']++;
        }
        auto it = hmap1.begin();
        bool ans;
        while (it != hmap1.end())
        {
            if (hmap1.count(it->first))
            {
                ans &= hmap2[it->first] >= it->second;
                it++;
                if (ans == false)
                    return false;
            }
            else
                return false;
        }
        return ans;
    }
};