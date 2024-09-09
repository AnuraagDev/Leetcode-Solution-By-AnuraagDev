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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int a=q.size();
            double sum=0;
            for(int i=0;i<a;i++){
                auto d=q.front();
                q.pop();
                if(d->left!=NULL)q.push(d->left);
                if(d->right!=NULL)q.push(d->right);
                sum+=d->val;
            }
            ans.push_back(sum/a);
        }return ans;
    }
};