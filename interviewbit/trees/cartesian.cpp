/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findMax(vector<int>& A, int s, int e) {
    int idx = -1;
    int val = INT_MIN;
    for (int i = s; i <= e; i++) {
        if (A[i] > val) {
            val = A[i];
            idx = i;
        }
    }
    return idx;
}
TreeNode* solve(vector<int> &A, int s, int e) {
    if (s > e) {
        return NULL;
    }
    int idx = findMax(A, s, e);
    TreeNode *T = new TreeNode(A[idx]);
    if (s == e) {
        return T;
    }
    T -> left = solve(A, s, idx - 1);
    T -> right = solve(A, idx + 1, e);
    return T;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return solve(A, 0, (int) A.size() - 1);
}
