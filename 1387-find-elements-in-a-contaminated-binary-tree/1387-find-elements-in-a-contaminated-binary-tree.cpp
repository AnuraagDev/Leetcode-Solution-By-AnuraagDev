class FindElements {
public:TreeNode* head;
unordered_set<int>se;
    FindElements(TreeNode* root) {
         root->val=0;
         head=root;
        solve(root);
    }
    void solve(TreeNode* root){
        if(root==nullptr)return;
        se.insert(root->val);
       if(root->right!=nullptr){root->right->val=(2*root->val)+2;solve(root->right);}
       if(root->left!=nullptr){root->left->val=(2*root->val)+1;solve(root->left);}
    
    }
    bool find(int target) {
        if(se.find(target)!=se.end())return 1;
        return 0;
    }
   
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */