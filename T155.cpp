// 最小栈 # 辅助栈法
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinStack
{
private:
    vector<int> stk;
    int top_index;
    int min;
    stack<int> min_stk;

public:
    MinStack()
    {
        this->top_index = -1;
        this->min = INT_MAX;
    }
    void push(int val)
    {
        stk.push_back(val);
        top_index++;
        min = val < min ? val : min;
        if (min_stk.empty())
        {
            min_stk.push(val);
            return;
        }
        if (val < min_stk.top())
        {
            min_stk.push(val);
        }
        else
        {
            min_stk.push(min_stk.top());
        }
    }
    void pop()
    {
        stk.pop_back();
        top_index--;
        min_stk.pop();
    }
    int top()
    {
        return stk[top_index];
    }
    int getMin()
    {
        return min_stk.top();
    }
};

int main()
{
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();
    minStack.pop();
    minStack.top();
    minStack.getMin();
}