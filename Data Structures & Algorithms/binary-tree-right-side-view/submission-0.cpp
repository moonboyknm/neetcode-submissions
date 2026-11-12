class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
       vector<int> res;
       dfs(root, 0, res);
       return res; 
    }

    void dfs(TreeNode* node, int level, vector<int>& res){
        if (node == nullptr) return;

        if (level == res.size()){
            res.push_back(node->val);
        }

        dfs(node->right, level + 1, res);
        dfs(node->left, level + 1, res);
    }
};
