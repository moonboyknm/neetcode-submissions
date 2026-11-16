class Solution {
public:
    int dfs(TreeNode* node, int maxVal){
        if (!node) return 0;

        int res = (node->val >= maxVal) ? 1 : 0;
        maxVal = max(node->val, maxVal);
        res += dfs(node->left, maxVal);
        res += dfs(node->right, maxVal);
        return res;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
