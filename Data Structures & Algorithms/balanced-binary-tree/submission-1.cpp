class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (!node) return 0;

        int left = checkHeight(node->left);
        if (left == -1) return -1; // Short-circuit early

        int right = checkHeight(node->right);
        if (right == -1) return -1; // Short-circuit early

        if (std::abs(left - right) > 1) return -1;

        return 1 + std::max(left, right);
    }
};