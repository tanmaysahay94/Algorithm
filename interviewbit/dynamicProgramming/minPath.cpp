int Solution::minPathSum(vector<vector<int> > &A) {
    vector<vector<int> > dp = A;
    for (int i = 1; i < (int) dp.size(); i++) {
        dp[i][0] += dp[i - 1][0];
    }
    for (int i = 1; i < (int) dp[0].size(); i++) {
        dp[0][i] += dp[0][i - 1];
    }
    for (int i = 1; i < (int) dp.size(); i++) {
        for (int j = 1; j < (int) dp[i].size(); j++) {
            dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[A.size() - 1][A[A.size() - 1].size() - 1];
}