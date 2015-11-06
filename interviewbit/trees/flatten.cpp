TreeNode* Solution::flatten(TreeNode* A) {
    if (not A) {
        return A;
    }
    TreeNode* L = A -> left;
    TreeNode* R = A -> right;
    A -> left = NULL;
    TreeNode* T = A;
    T -> right = flatten(L);
    while (T -> right) {
        T = T -> right;
    }
    T -> right = flatten(R);
    return A;
}
