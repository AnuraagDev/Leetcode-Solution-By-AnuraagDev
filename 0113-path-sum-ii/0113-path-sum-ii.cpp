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
vector<vector<int>>ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<int>a;
        bfs(root,targetSum,a);
        return ans;

    }
    void bfs(TreeNode* root,int target,vector<int>&a){
        if(root==nullptr)return;
        if(root->left==nullptr&&root->right==nullptr){
           if( target-root->val==0 ){
            a.push_back(root->val);
            ans.push_back(a);
            a.pop_back();
           }
           return;
        }
        a.push_back(root->val);
        bfs(root->left,target-root->val,a);
        bfs(root->right,target-root->val,a);
        a.pop_back();
    }
};