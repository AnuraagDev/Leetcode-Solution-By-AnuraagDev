/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)return 0;
        return bfs(root,targetSum,0);
    }
    bool bfs(TreeNode* root,int target,int sum){
        if(root==nullptr)return target==sum;
        return bfs(root->left,target,sum+root->val)||bfs(root->right,target,sum+root->val);   }
};