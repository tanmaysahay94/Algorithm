int Solution::maxProfit(const vector<int> &A) {
    int mn = INT_MAX, foo = 0;
    for (int i = 0; i < (int) A.size(); i++) {
        if (A[i] < mn) {
            mn = A[i];
        }
        foo = max(foo, A[i] - mn);
    }
    return foo;
}