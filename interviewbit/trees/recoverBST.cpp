/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // inorder traversal from left to find first invalid node
bool foo(vector<int>& ret, TreeNode* A, TreeNode** T) {
    if (not A) {
        return false;
    }
    bool left = foo(ret, A -> left, T);
    if (left) {
        return left;
    }
    if (not (*T)) {
        *T = A;
    }
    else if ((*T) -> val > A -> val) {
        ret.push_back((*T) -> val);
        return true;
    }
    *T = A;
    return foo(ret, A -> right, T);
}

// inorder traversal from right to find the other invalid node
bool bar(vector<int>& ret, TreeNode* A, TreeNode** T) {
    if (not A) {
        return false;
    }
    bool right = bar(ret, A -> right, T);
    if (right) {
        return right;
    }
    if (not (*T)) {
        *T = A;
    }
    else if ((*T) -> val < A -> val) {
        ret.push_back((*T) -> val);
        return true;
    }
    *T = A;
    return bar(ret, A -> left, T);
}

vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> ret;
    TreeNode* T = NULL;
    // get left invalid
    bar(ret, A, &T);
    T = NULL;
    // get right invalid
    foo(ret, A, &T);
    sort(ret.begin(), ret.end());
    return ret;
}
