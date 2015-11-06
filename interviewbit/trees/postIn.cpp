/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int find(vector<int>& in, int val, int s, int e) {
    for (int i = s; i <= e; i++) {
        if (in[i] == val) {
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int>& in, vector<int>& post, int& idx, int s, int e) {
    if (s > e) {
        idx++;
        return NULL;
    }
    TreeNode* T = new TreeNode(post[idx]);
    if (s == e) {
        return T;
    }
    int foo = find(in, post[idx], s, e);
    T -> right = solve(in, post, --idx, foo + 1, e);
    T -> left = solve(in, post, --idx, s, foo - 1);
    return T;
}
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    int sz = postorder.size() - 1;
    return solve(inorder, postorder, sz, 0, sz);
}
