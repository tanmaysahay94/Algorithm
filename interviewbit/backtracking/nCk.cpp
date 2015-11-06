void solve(int curr, int n, int k, vector<vector<int> >& ret, vector<int>& row) {
    if (k == (int) row.size()) {
        ret.push_back(row);
        return;
    }
    if (curr > n) {
        return;
    }
    row.push_back(curr);
    solve(curr + 1, n, k, ret, row);
    row.pop_back();
    solve(curr + 1, n, k, ret, row);
}
vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int> > ret;
    vector<int> row;
    solve(1, n, k, ret, row);
    for (int i = 0; i < (int) ret.size(); i++) {
        sort(ret[i].begin(), ret[i].end());
    }
    sort(ret.begin(), ret.end());
    return ret;
}
