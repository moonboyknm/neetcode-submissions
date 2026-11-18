class Solution {
   public:
    bool isValidBST(TreeNode* root) { return isValid(root, nullptr, nullptr); }

   private:
    bool isValid(TreeNode* node, TreeNode* min_node, TreeNode* max_node) {
        if (!node) return true;

        if (min_node && node->val <= min_node->val) return false;
        if (max_node && node->val >= max_node->val) return false;

        return isValid(node->left, min_node, node) && isValid(node->right, node, max_node);
    }
};