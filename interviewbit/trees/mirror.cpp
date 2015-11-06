int solve(TreeNode* L, TreeNode* R) {
    if (R and not L) {
        return 0;
    }
    if (L and not R) {
        return 0;
    }
    if (not L and not R) {
        return 1;
    }
    if (L and R) {
        if (L -> val != R -> val) {
            return 0;
        }
        else {
            return solve(L -> left, R -> right) and solve(L -> right, R -> left);
        }
    }
}
int Solution::isSymmetric(TreeNode* A) {
    return solve(A -> left, A -> right);
}
