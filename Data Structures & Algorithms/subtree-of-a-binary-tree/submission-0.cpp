class Solution {
private:
    // Helper function from LC 100: Same Tree
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // An empty root cannot contain a non-empty subRoot
        if (!root) return false;

        // If they match from the current root, we found it
        if (isSameTree(root, subRoot)) return true;

        // Otherwise, recursively check left and right children
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};