vector<int> clean(vector<int>& A) {
    set<int> S;
    for (auto a: A) {
        S.insert(a);
    }
    A.clear();
    for (auto s: S) {
        A.push_back(s);
    }
    return A;
}
void solve(vector<vector<int> >& ret, vector<int>& A, vector<int>& row, int sum, int idx) {
    if (sum == 0) {
        ret.push_back(row);
        return;
    }
    if (sum < 0) {
        return;
    }
    if (idx == (int) A.size()) {
        return;
    }
    row.push_back(A[idx]);
    solve(ret, A, row, sum - A[idx], idx);
    row.pop_back();
    solve(ret, A, row, sum, idx + 1);
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    A = clean(A);
    vector<vector<int> > ret;
    vector<int> row;
    solve(ret, A, row, B, 0);
    return ret;
}
