/* T9:回文数  # 双指针法 #数学取余数法
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 */
// 法1：字符串法+双指针
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        else if (x == 0)
            return true;
        else if (x > 0)
        {
            string string_x = to_string(x);
            int len = string_x.size();
            for (int i = 0, j = len - 1; i < j; j--, i++)
            {
                if (string_x[i] != string_x[j])
                    return false;
            }
            return true;
        }
        return true;
    }
};

// 法2：数学法
class Solution2
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        else if (x == 0)
            return true;
        else if (x % 10 == 0 && x != 0)
            return false; // 末尾为0且不为0的数不可能是回文数
        else if (x > 0)
        {
            int fanzhuan = 0;
            while (fanzhuan < x)
            {
                fanzhuan = fanzhuan * 10 + x % 10;
                x = x / 10;
                if (x == fanzhuan)
                    return true;
            }
            if (x == fanzhuan / 10)
                return true;
            else
                return false;
        }
        return true;
    }
};

int main()
{
    Solution2 sol;
    cout << sol.isPalindrome(121) << endl;
    cout << sol.isPalindrome(-121) << endl;
    cout << sol.isPalindrome(10) << endl;
    cout << sol.isPalindrome(12321) << endl;
    cout << sol.isPalindrome(0) << endl;
    cout << sol.isPalindrome(1) << endl;
    cout << sol.isPalindrome(1234321) << endl;
    cout << sol.isPalindrome(12344321) << endl;
    return 0;
}