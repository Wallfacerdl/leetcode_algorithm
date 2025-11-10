// 字符串解码
#include <iostream>
#include <string>
using namespace std;
// 自己的思路：递归法（未优化：通过拷贝字符串作为每次递归的输入造成了大量的开销）
class Solution
{
private:
    int pos;

public:
    string decodeString(string s)
    {
        pos = 0;
        return decodeHelper(s);
    }
    string decodeHelper(string s)
    {
        {
            int length = s.size();
            string res = "";
            // 事实上并不需要该字符型变量，可以直接通过str-'0'的方法来转化整型
            string count = "";
            int count_int = 1;               // 这里其实可以放在循环内部，而不需要每次在执行最后的地方在重新初始化
            for (int i = 0; i < length; i++) // 并不需要用i标记位置,pos标记绝对位置已经达到了标记子字符串的目的
            {
                pos++;
                if (s[i] == '[')
                {
                    int start = i;   // 记录'['位置(在s中的绝对位置)
                    int first = pos; // pos为在全局中的绝对位置
                    if (count == "") // 没有前面的数字，默认重复1次
                    {                // s.substr(i + 1):最大问题，造成了大量的开销
                        res += decodeHelper(s.substr(i + 1));
                    }
                    else
                    {

                        string tmp_str = decodeHelper(s.substr(i + 1));
                        for (int j = 0; j < count_int; j++)
                        {
                            res += tmp_str;
                        }
                    }
                    int offset = pos - first; // 位移量
                    i += offset;
                    count_int = 1; // 改完之后这里就不再需要初始化
                    count = "";
                }
                else if (s[i] == ']')
                {
                    return res;
                }

                else if (isdigit(s[i]))
                {
                    count += s[i];
                    count_int = stoi(count);
                }
                else // 普通字符
                {
                    res += s[i];
                }
            }
            return res;
        }
    }
};

// 改进代码:
// 核心思想：通过数字索引来定位和遍历原始字符串，是解决这类嵌套
// 结构字符串解码问题的关键优化点。这种方法避免了频繁创建子字符串带来的性能开销
class Solution2
{
private:
    int pos;

public:
    string decodeString(string s)
    {
        pos = 0;
        return decodeHelper(s);
    }
    string decodeHelper(string s)
    {
        {
            string result = "";
            int count = 0;
            while (pos < s.size())
            {
                if (s[pos] == '[')
                {
                    pos++;                               // 全局指针后移
                    string tmp_string = decodeHelper(s); // 返回括号里面的内容
                    while (count > 0)
                    {
                        result += tmp_string;
                        count--;
                    }
                }
                else if (s[pos] == ']')
                {
                    pos++;         // 全局指针后移
                    return result; // 当前层结束递归，返回这一层的字符内容
                }

                else if (isdigit(s[pos]))
                {
                    while (isdigit(s[pos]))
                    {
                        count = 10 * count + (s[pos] - '0');
                        pos++; // 全局指针后移
                    }
                }
                else if (isalpha(s[pos])) // 普通字符
                {
                    result += s[pos++];
                }
            }
            return result;
        }
    }
};
// 测试
int main()
{
    Solution2 sol;
    string s = "2[2[y]pq4[2[jk]e1[f]]]";
    string s2 = "100[leetcode]";
    string s2_result = sol.decodeString(s2);
    cout << s2_result << endl;
    return 0;
}