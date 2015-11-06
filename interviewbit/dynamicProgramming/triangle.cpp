int Solution::minimumTotal(vector<vector<int> > &A) {
    vector<vector<int> > dp = A;
    int n = dp.size();
    for (int i = n - 2; i >= 0; i--) {
        for (int j = dp[i].size() - 1; j >= 0; j--) {
            dp[i][j] += min(dp[i + 1][j + 1], dp[i + 1][j]);
        }
    }
    return dp[0][0];
}