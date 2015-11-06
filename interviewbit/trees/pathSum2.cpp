void solve(TreeNode* A, int sum, vector<vector<int> >& ret, vector<int>& path) {
    if (not A) {
        return;
    }
    sum -= A -> val;
    path.push_back(A -> val);
    if (not A -> left and not A -> right) {
        if (sum == 0) {
            ret.push_back(path);
        }
        path.pop_back();
        return;
    }
    solve(A -> left, sum, ret, path);
    solve(A -> right, sum, ret, path);
    path.pop_back();
}

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    vector<vector<int> > ret;
    vector<int> path;
    solve(root, sum, ret, path);
    sort(ret.begin(), ret.end());
    return ret;
}
