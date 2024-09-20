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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>s;
        solve(s,root,"");return s;
    }
    void solve(vector<string>&s,TreeNode* root,string ans){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr&&root->right==nullptr){
            ans+=to_string(root->val);
            s.push_back(ans);
        }
        ans+=to_string(root->val);
        ans+="->";
        solve(s,root->left,ans);
        solve(s,root->right,ans);
    }
};