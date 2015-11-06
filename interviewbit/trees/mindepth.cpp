void solve(TreeNode *A, int level, int& ans) {
    if (not A -> left and not A -> right) {
        ans = min(ans, level);
        return;
    }
    if (A -> left) {
        solve(A -> left, level + 1, ans);
    }
    if (A -> right) {
        solve(A -> right, level + 1, ans);
    }
}

int Solution::minDepth(TreeNode* A) {
    int ans = INT_MAX;
    solve(A, 1, ans);
    return ans;
}
