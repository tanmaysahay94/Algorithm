TreeNode* Solution::invertTree(TreeNode* root) {
    if (not root) {
        return NULL;
    }
    TreeNode* l = invertTree(root -> left);
    TreeNode* r = invertTree(root -> right);
    root -> left = r;
    root -> right = l;
    return root;
}
