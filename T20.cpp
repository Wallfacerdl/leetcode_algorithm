/*
T20：有效的括号 # 哈希匹配 # 栈

*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {

        if (s.size() % 2 == 1)
            return false;

        // 定义一个哈希用于匹配
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}};

        stack<char> s1;
        for (char character : s)
        {
            if (pairs.count(character)) // ch是右括号之一
            {
                if (s1.empty() || s1.top() != pairs[character]) // s1为空或者栈顶不匹配ch
                    return false;
                else
                    s1.pop();
            }
            else
            {
                s1.push(character);
            }
        }
        return s1.empty();
    }
};