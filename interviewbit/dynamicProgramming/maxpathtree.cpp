/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode* T, int &mx) {
    if (!T) {
        return 0;
    }
    int lmx = solve(T -> left, mx);
    int rmx = solve(T -> right, mx);
    int single = max(T -> val, T -> val + max(lmx, rmx));
    int top = max(T -> val, max(single, lmx + rmx + T -> val));
    mx = max(mx, top);
    return single;
}
int Solution::maxPathSum(TreeNode* A) {
    int ret = INT_MIN;
    solve(A, ret);
    return ret;
}