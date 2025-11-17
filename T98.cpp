// T98.验证二叉搜索树
#include <iostream>
#include <vector>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using namespace std;
// class Solution
// {
// public:
//     bool isValidBST(TreeNode *root)
//     {
//         return isValidBST_helper(root, INT_MIN, "default");
//     }
//     bool isValidBST_helper(TreeNode *root, int last_root_val, string branch)
//     {
//         // branch表示是last_root_val节点的左或右分支
//         //  特殊值处理
//         if (root == nullptr)
//             return true;
//         // 一般情况
//         if (root->left == nullptr && root->right == nullptr)
//             return true;
//         else if (root->left == nullptr)
//         {
//             int val = root->right->val;
//             if (branch == "left")
//             {
//                 return val > root->val;
//             } // 可以省略val 《 last_root_val（肯定大于）
//             else if (branch == "right")
//             {
//                 return val > last_root_val && val > root->val;
//             }

//             else
//                 return (val > root->val);
//         }
//         else if (root->right == nullptr)
//         {
//             int val = root->left->val;
//             if (branch == "left")
//             {
//                 return val < root->val && val < last_root_val;
//             } // 可以省略val<
//             else if (branch == "right")
//             {
//                 return val > root->val;
//             } // 可以省略val > last_root_val（肯定大于）
//             else
//                 return val < root->val;
//         }
//         else // 两个子节点都非空
//         {
//             bool ans = true;
//             if (branch == "left") // 左边分支都要小于上一个根节点
//             {
//                 ans &= root->right->val < last_root_val;
//             }
//             else if (branch == "right") // 右边分支时，左节点都要大于上一个根节点（右子节点显然更大）
//             {
//                 ans &= root->left->val > last_root_val;
//             }
//             ans &= (root->left->val < root->val && root->val < root->right->val);
//             cout << root->val << " " << ans << endl;
//             if (ans == false)
//                 return false;
//             return ans && isValidBST_helper(root->left, root->val, "left") && isValidBST_helper(root->right, root->val, "right");
//         }
//     }
// };

class Solution2
{
public:
    bool isValidBST(TreeNode *root)
    {
        // 用一个数组存储中序遍历结果
        vector<int> result_v;
        bool ans = true;
        midBST2vector(root, result_v);
        for (int i = 0; i < result_v.size() - 1; i++)
        {
            cout << result_v[i];
            ans &= (result_v[i] < result_v[i + 1]);
        }
        return ans;
    }
    void midBST2vector(TreeNode *root, vector<int> &result_v)
    {
        if (root == nullptr)
            return;
        midBST2vector(root->left, result_v);
        cout << root->val;
        result_v.push_back(root->val);
        midBST2vector(root->right, result_v);
        cout << "test";
    }
};
class Solution3
{
private:
    long int last_val = LONG_MIN;

public:
    bool isValidBST(TreeNode *root)
    {
        bool ans = true;
        if (root == nullptr)
            return true;
        ans &= isValidBST(root->left);
        if (last_val != LONG_MIN && root->val <= last_val)
            return false;
        last_val = root->val;
        if (ans == false)
            return false; // 有问题提前退出
        ans &= isValidBST(root->right);
        return ans;
    }
};
int main()
{
    TreeNode *root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    // test: [2,1,3]
    Solution2 sol;
    sol.isValidBST(root);
}