void solve(vector<vector<int> >& ret, TreeNode* A, int level) {
    if (A) {
        if (ret.size() < level) {
            vector<int> row;
            row.push_back(A -> val);
            ret.push_back(row);
        }
        else {
            ret[level - 1].push_back(A -> val);
        }
        solve(ret, A -> left, level + 1);
        solve(ret, A -> right, level + 1);
    }
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > ret;
    solve(ret, A, 1);
    for (int i = 1; i < (int) ret.size(); i += 2) {
        reverse(ret[i].begin(), ret[i].end());
    }
    return ret;
}
