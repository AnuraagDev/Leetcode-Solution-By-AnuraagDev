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
    int minDepth(TreeNode* root) {
        return solve(root);
    }
    int solve(TreeNode* root){
        if(root==NULL)return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        if (l == 0 || r == 0) return max(l, r) + 1;
        return min(l,r)+1;
    }

};