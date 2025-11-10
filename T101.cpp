// 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        else
        {return is_duicheng(root->left,root->right);}
    }

    bool is_duicheng(TreeNode *left,TreeNode *right)
    {
        // cout << "left:" << (left ? left->val : -1) << " right:" << (right ? right->val : -1) << endl;
        if (left == nullptr || right == nullptr) // 递归的终点:两者中出现空节点
        {
            return left == right; // 只要出现了空节点，那么必然两个同时为空节点才能返回true
        }
        // 短路求值（short-circuit evaluation）提前终止递归，减少栈深度
        else if (left->val != right->val) return false;
        return is_duicheng(left->left,right->right) && is_duicheng(left->right,right->left);
        
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << sol.isSymmetric(root) << endl; // 1

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);
    cout << sol.isSymmetric(root2) << endl; // 0

    return 0;
}