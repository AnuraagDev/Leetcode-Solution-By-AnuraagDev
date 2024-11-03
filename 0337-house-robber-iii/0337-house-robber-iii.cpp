class Solution {
public:
    int rob(TreeNode* root) {
        // Memoization map to store results for each node
        unordered_map<TreeNode*, int> memo;
        return solve(root, memo);
    }

private:
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& memo) {
        if (!root) return 0;

        // Check if the result for this node is already computed
        if (memo.count(root)) return memo[root];

        // Calculate 'include': rob current node and skip its direct children
        int include = root->val;
        if (root->left) {
            include += solve(root->left->left, memo) + solve(root->left->right, memo);
        }
        if (root->right) {
            include += solve(root->right->left, memo) + solve(root->right->right, memo);
        }

        // Calculate 'exclude': don't rob current node, so we can rob children
        int exclude = solve(root->left, memo) + solve(root->right, memo);

        // Store the result in memo and return the max of include and exclude
        memo[root] = max(include, exclude);
        return memo[root];
    }
};
