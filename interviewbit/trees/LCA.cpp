TreeNode* findLCA(TreeNode* A, int v1, int v2) {
    if (not A) {
        return NULL;
    }
    if (A -> val == v1 or A -> val == v2) {
        return A;
    }
    TreeNode* left = findLCA(A -> left, v1, v2);
    TreeNode* right = findLCA(A -> right, v1, v2);
    if (left and right) {
        return A;
    }
    if (left) {
        return left;
    }
    return right;
}
bool isPresent(TreeNode* A, int v) {
    if (not A) {
        return 0;
    }
    if (A -> val == v) {
        return 1;
    }
    return isPresent(A -> left, v) or isPresent(A -> right, v);
}
int Solution::lca(TreeNode* A, int val1, int val2) {
    if (isPresent(A, val1) and isPresent(A, val2)) {
        return findLCA(A, val1, val2) -> val;
    }
    return -1;
}
