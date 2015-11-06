int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int, int> > v(A.size());
    vector<int> imax(A.size());
    for (int i = 0; i < (int) A.size(); i++) {
        v[i].first = A[i];
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int foo = INT_MIN;
    for (int i = A.size() - 1; i >= 0; i--) {
        foo = max(foo, v[i].second);
        imax[i] = foo;
    }
    for (int i = 0; i < (int) A.size(); i++) {
        ans = max(imax[i] - v[i].second, ans);
    }
    return ans;
}
