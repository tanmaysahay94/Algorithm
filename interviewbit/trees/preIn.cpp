int idxOf(int v, vector<int>& V, int s, int e) {
    for (int i = s; i <= e; i++) {
        if (V[i] == v) {
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int>& pre, vector<int>& in, int s, int e, int& idx) {
    if (s > e) {
        idx--;
        return NULL;
    }
    TreeNode* T = new TreeNode(pre[idx]);
    if (s == e) {
        return T;
    }
    int loc = idxOf(T -> val, in, s, e);
    T -> left = solve(pre, in, s, loc - 1, ++idx);
    T -> right = solve(pre, in, loc + 1, e, ++idx);
    return T;
}
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    int idx = 0;
    return solve(preorder, inorder, 0, inorder.size() - 1, idx);
}
