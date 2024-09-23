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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* a=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insert(preorder[i],a);
        }
        return a;
    }
    void insert(int w,TreeNode* q){
        if(q->val<w){
            if(q->right==nullptr){
                TreeNode* temp=new TreeNode(w);
                q->right=temp;
                return;
            }
            insert(w,q->right);
        }
        else{
            if(q->left==nullptr){
                TreeNode* temp=new TreeNode(w);
                q->left=temp;
                return;
            }
            insert(w,q->left);
        }
        
    }
};