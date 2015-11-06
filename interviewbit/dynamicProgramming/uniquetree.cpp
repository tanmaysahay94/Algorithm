int Solution::numTrees(int A) {
    vector<int> dp(A + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= A; i++) {
        for (int j = i; j > 0; j--) {
            dp[i] += dp[i - j] * dp[j - 1];
        }
    }
    return dp[A];
}
