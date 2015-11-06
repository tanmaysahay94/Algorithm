/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* solve(const vector<int> &A, int s, int e) {
    if (s > e) {
        return NULL;
    }
    int m = (s + e); m >>= 1;
    TreeNode *T = new TreeNode(A[m]);
    if (s == e) {
        return T;
    }
    T -> left = solve(A, s, m - 1);
    T -> right = solve(A, m + 1, e);
    return T;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return solve(A, 0, A.size() - 1);
}
