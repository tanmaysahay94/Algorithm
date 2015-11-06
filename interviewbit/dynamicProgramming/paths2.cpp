int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    vector<vector<int> > dp(m, vector<int> (n));
    if (A[0][0] == 0) {
        dp[0][0] = 1;
    }
    for (int row = 1; row < m; row++) {
        dp[row][0] = 1;
    }
    int idx = 0;
    while (idx < m) {
        if (A[idx][0] == 1) {
            break;
        }
        idx++;
    }
    for (int row = idx; row < m; row++) {
        dp[row][0] = 0;
    }
    for (int col = 1; col < n; col++) {
        dp[0][col] = 1;
    }
    idx = 0;
    while (idx < n) {
        if (A[0][idx] == 1) {
            break;
        }
        idx++;
    }
    for (int col = idx; col < n; col++) {
        dp[0][col] = 0;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = (A[i - 1][j] == 0) * dp[i - 1][j] + (A[i][j - 1] == 0) * dp[i][j - 1];
            if (A[i][j] == 1) {
                dp[i][j] = 0;
            }
        }
    }
    return dp[m - 1][n - 1];
}