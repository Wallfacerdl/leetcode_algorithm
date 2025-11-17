// 108.有序二叉树组转化为二叉搜索树
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int length = nums.size();
        return sortedArrayToBST_in_index(nums, 0, length - 1);
    }
    TreeNode *sortedArrayToBST_in_index(vector<int> &nums, int begin, int end)
    {
        if (begin > end)
            return nullptr;
        else
        {

            int mid = (begin + end) / 2;
            TreeNode *ans = new TreeNode(nums[mid]);
            ans->left = sortedArrayToBST_in_index(nums, begin, mid - 1);
            ans->right = sortedArrayToBST_in_index(nums, mid + 1, end);
            return ans;
        }
    }
};
int main()
{
    // [1,3]
    Solution sol;
    vector<int> v(1, 3);
    TreeNode *res = sol.sortedArrayToBST(v);
    // 遍历res
    cout << res->val << endl;
}