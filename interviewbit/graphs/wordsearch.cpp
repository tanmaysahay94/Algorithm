int search(vector<string> &A, string &B, int idx, int i, int j, int r, int c) {
    if (idx == (int) B.size()) {
        return 1;
    }
    if (i < 0 or j < 0 or i >= r or j >= c) {
        return 0;
    }
    if (B[idx] == A[i][j]) {
        return search(A, B, idx + 1, i + 1, j, r, c)
        or search(A, B, idx + 1, i - 1, j, r, c)
        or search(A, B, idx + 1, i, j + 1, r, c)
        or search(A, B, idx + 1, i, j - 1, r, c);
    }
    return 0;
}
int Solution::exist(vector<string> &A, string B) {
    int n = A.size();
    int m = A[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (search(A, B, 0, i, j, n, m)) {
                return 1;
            }
        }
    }
    return 0;
}