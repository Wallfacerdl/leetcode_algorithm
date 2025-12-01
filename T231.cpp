// 231.2的幂 # 递归 #位运算

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;
        else if (n == 1)
            return true;
        if (n % 2 == 1)
            return false;
        return isPowerOfTwo(n / 2);
    }
};
class Solution2
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        return n & (n - 1);
    }
};