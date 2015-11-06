int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        if (1 <= A[i] and A[i] <= n) {
            int idx = A[i] - 1;
            if (A[idx] != A[i]) {
                swap(A[idx], A[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}