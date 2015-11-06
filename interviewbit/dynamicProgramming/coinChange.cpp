const int mod = 1000007;

int Solution::coinchange2(vector<int> &A, int B) {
    int n = A.size();
    vector<int> dp(B + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = A[i]; j <= B; j++) {
            dp[j] += dp[j - A[i]];
            dp[j] %= mod;
        }
    }
    return dp[B];
}