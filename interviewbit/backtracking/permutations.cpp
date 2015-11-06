void solve(vector<vector<int> >& ret, vector<int>& A, int l, int r) {
    if (l == r) {
        ret.push_back(A);
        return;
    }
    else {
        for (int i = l; i <= r; i++) {
            swap(A[i], A[l]);
            solve(ret, A, l + 1, r);
            swap(A[i], A[l]);
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int> > ret;
    solve(ret, A, 0, (int) A.size() - 1);
    sort(ret.begin(), ret.end());
    return ret;
}
