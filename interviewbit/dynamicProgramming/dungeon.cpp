int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    vector<vector<int> > DP(m, vector<int> (n));
    DP[m - 1][n - 1] = max(1, 1 - A[m - 1][n - 1]);
    for (int j = n - 2; j >= 0; j--) {
        DP[m - 1][j] = max(1, max(1 - A[m - 1][j], DP[m - 1][j + 1] - A[m - 1][j]));
    }
    for (int i = m - 2; i >= 0; i--) {
        DP[i][n - 1] = max(1, max(1 - A[i][n - 1], DP[i + 1][n - 1] - A[i][n - 1]));
    }
    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            DP[i][j] = max(1, max(1 - A[i][j], min(DP[i + 1][j], DP[i][j + 1]) - A[i][j]));
        }
    }
    return DP[0][0];
}