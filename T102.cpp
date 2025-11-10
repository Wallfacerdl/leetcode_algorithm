// 102.二叉树的层次遍历 # 广度优先搜索 # 队列

#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> sub_v;
            int size = q.size(); // 当前层拥有的节点数
            for (int j = 0;j<size;j++)
            {
                TreeNode* node = q.front();
                q.pop();
                sub_v.push_back(node->val);
                //只添加非空的节点
                if (node->left != nullptr) {q.push(node->left);}
                if (node->right != nullptr) {q.push(node->right);}
            }
            result.push_back(std::move(sub_v)); // 使用move避免不必要的拷贝
        }
        return result;
    }
};