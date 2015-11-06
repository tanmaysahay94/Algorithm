bool isPalin(string& A) {
    int l = 0, r = A.size() - 1;
    while (l <= r) {
        if (A[l] != A[r]) {
            return 0;
        }
        l++, r--;
    }
    return 1;
}
void solve(vector<string>&row, vector<vector<string> > &ret, string &S, int idx, int n) {
    if (idx == n) {
        ret.push_back(row);
        return;
    }
    string foo("");
    for (int i = idx; i < n; i++) {
        foo.push_back(S[i]);
        if (isPalin(foo)) {
            row.push_back(foo);
            solve(row, ret, S, i + 1, n);
            row.pop_back();
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
    vector<string> row;
    vector<vector<string> > ret;
    solve(row, ret, A, 0, A.length());
    return ret;
}
