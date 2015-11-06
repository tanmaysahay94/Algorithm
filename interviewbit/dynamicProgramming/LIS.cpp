int Solution::lis(const vector<int> &A) {
    int n = A.size();
    vector<int> LIS(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] and LIS[i] < LIS[j] + 1) {
                LIS[i] = LIS[j] + 1;
            }
        }
    }
    int ans = 0;
    for (auto L: LIS) {
        ans = max(ans, L);
    }
    return ans;
}