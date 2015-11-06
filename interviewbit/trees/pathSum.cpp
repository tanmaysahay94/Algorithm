int Solution::hasPathSum(TreeNode* A, int B) {
    if (not A) {
        return 0;
    }
    B -= A -> val;
    if (not A -> left and not A -> right) {
        if (B == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    return hasPathSum(A -> left, B) or hasPathSum(A -> right, B);
}
