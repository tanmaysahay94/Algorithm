int Solution::minDistance(string A, string B) {
    int n = A.size();
    int m = B.size();
    vector<vector<int> >dp(n + 1, vector<int> (m + 1));
    for (int col = 0; col <= m; col++) {
        dp[0][col] = col;
    }
    for (int row = 0; row <= n; row++) {
        dp[row][0] = row;
    }
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            if (A[row - 1] == B[col - 1]) {
                dp[row][col] = dp[row - 1][col - 1];
            }
            else {
                dp[row][col] = 1 + min(dp[row - 1][col - 1], min(dp[row - 1][col], dp[row][col - 1]));
            }
        }
    }
    return dp[n][m];
}