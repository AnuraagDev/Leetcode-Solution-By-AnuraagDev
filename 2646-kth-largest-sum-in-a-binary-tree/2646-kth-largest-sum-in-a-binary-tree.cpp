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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ani;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
           int c=q.size();
           long long ans=0;
           while(c--){
            auto d=q.front();
            q.pop();
            if(d->left!=nullptr)q.push(d->left);
            if(d->right!=nullptr)q.push(d->right);
            ans+=(d->val);
           }
           ani.push_back(ans);
        }
        sort(ani.rbegin(),ani.rend());
        for(auto i:ani)cout<<i<<" ";
        if(k>ani.size())return -1;
        return ani[k-1];
    }
};