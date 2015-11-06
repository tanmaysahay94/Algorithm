void solve(vector<int>& A, int B, vector<vector<int> >& ret, vector<int>& row, int idx, int sum) {
    if (sum == B) {
        int cnt = 0;
        if (ret.empty() or ret[ret.size() - 1].size() != row.size()) {
            ret.push_back(row);
        }
        else {
            for (int i = 0; i < (int) row.size(); i++) {
                if (ret[ret.size() - 1][i] == row[i]) {
                    cnt++;
                }
            }
            if (cnt != (int) row.size()) {
                ret.push_back(row);
            }
        }
        return;
    }
    if (sum > B or idx == (int) A.size()) {
        return;
    }
    row.push_back(A[idx]);
    solve(A, B, ret, row, idx + 1, sum + A[idx]);
    row.pop_back();
    solve(A, B, ret, row, idx + 1, sum);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int> > ret;
    vector<int> row;
    solve(A, B, ret, row, 0, 0);
    return ret;
}
