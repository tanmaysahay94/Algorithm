vector<vector<int> > Solution::subsets(vector<int> &A) {
    int n = A.size();
    int lim = 1 << n;
    vector<vector<int> > ret;
    for (int i = 0; i < lim; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                row.push_back(A[j]);
            }
        }
        ret.push_back(row);
    }
    for (auto &r: ret) {
        sort(r.begin(), r.end());
    }
    sort(ret.begin(), ret.end());
    return ret;
}
