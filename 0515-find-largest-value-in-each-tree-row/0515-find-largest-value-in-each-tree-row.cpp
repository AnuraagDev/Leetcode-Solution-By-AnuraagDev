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
    vector<int> largestValues(TreeNode* root) {
        vector<int>Ans;
        queue<TreeNode*>q;
        if(root==nullptr)return Ans;
        q.push(root);
        while(!q.empty()){
            int c=q.size();
            int ans=INT_MIN;
            for(int i=0;i<c;i++){
                auto d=q.front();
                q.pop();
                if(d->right!=nullptr)q.push(d->right);
                if(d->left!=nullptr)q.push(d->left);
                ans=max(ans,d->val);

            }
            Ans.push_back(ans);
        }
        return Ans;
        
    }
};