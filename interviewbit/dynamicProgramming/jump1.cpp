int Solution::canJump(vector<int> &A) {
    int n = A.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i > ans) {
            return 0;
        }
        ans = max(ans, i + A[i]);
    }
    return 1;
}