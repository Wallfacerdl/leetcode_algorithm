// 二叉树的最大深度 # 递归法 # DFS
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0; // 设置初始条件
        else if (root -> left == nullptr && root -> right == nullptr) return 1; // 设置终止条件
        else return max(1 + maxDepth(root->left),1 + maxDepth(root->right));
    }
};