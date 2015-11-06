int Solution::trap(const vector<int> &A) {
    int ret = 0;
    int n = A.size();
    vector<int> left(n, -1), right(n, -1);
    left[0] = A[0], right[n - 1] = A[n - 1];
    for (int i = 1, j = n - 2; i < n and j >= 0; i++, j--) {
        left[i] = max(left[i - 1], A[i]);
        right[j] = max(right[j + 1], A[j]);
    }
    for (int i = 0; i < n; i++) {
        int foo = min(left[i], right[i]);
        if (foo > A[i]) {
            ret += foo - A[i];
        }
    }
    return ret;
}
