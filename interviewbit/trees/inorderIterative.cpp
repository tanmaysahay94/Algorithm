vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ret;
    stack<TreeNode*> S;
    TreeNode* curr = A;
    bool done = false;
    while (not done) {
        if (curr) {
            S.push(curr);
            curr = curr -> left;
        }
        else {
            if (S.empty()) {
                done = true;
            }
            else {
                curr = S.top();
                S.pop();
                ret.push_back(curr -> val);
                curr = curr -> right;
            }
        }
    }
    return ret;
}
