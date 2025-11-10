// 543.二叉树的直径 # 递归 # dfs

// 给定一棵二叉树，你需要计算它的直径长度。二叉树的直径长度是指
// 任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

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
    int get_depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(get_depth(root->left), get_depth(root->right));
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        // 左子节点长度+右子节点长度
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return 0;
        int left_length = get_depth(root->left);
        int right_length = get_depth(root->right);
        return left_length + right_length;
    }
};
class Solution2
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int depth = 0;
        return maxDepth(root, depth);
    }
    int maxDepth(TreeNode *root, int &depth)
    {
        if (root == nullptr)
            return 0;
        // if (root->left) return max(1+ maxDepth(root->left,depth),depth);
        // else return max(1+ maxDepth(root->right,depth),depth);
        // depth = max( maxDepth(root->left,depth) + maxDepth(root->right,depth),depth);
        // return depth;
        if ((root->left == nullptr && root->right == nullptr))
            return 1;
        // 终止递归条件
        depth = max(max(maxDepth(root->left, depth + 1), maxDepth(root->right, depth + 1)));
        return depth;
    }
};

// 测试用例root =
// [1,2,3,4,5]
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution2 sol;
    cout << sol.diameterOfBinaryTree(root) << endl; // 4
    return 0;
}