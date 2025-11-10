// 反转二叉树  # 递归法（DFS）
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        else
        {
            TreeNode *tmp_node;
            tmp_node = invertTree(root->left);
            root->left = invertTree(root->right);
            root->right = tmp_node;
            return root;
        }
    }
};
