int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<int> dp(n + 1, 0);
    int ans = dp[n - 1] = max(A[0][n - 1], A[1][n - 1]), maxVal = 0;
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = max(A[0][i], A[1][i]) + (maxVal = max(dp[i + 2], maxVal));
        ans = max(ans, dp[i]);
    }
    return ans;
}