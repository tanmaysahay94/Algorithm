void mark(vector<string> &A, vector<vector<int> > &vis, int i, int j, int r, int c) {
    if (i == r or j == c or i < 0 or j < 0) {
        return;
    }
    if (A[i][j] == 'O') {
        return;
    }
    if (vis[i][j]) {
        return;
    }
    vis[i][j] = 1;
    mark(A, vis, i + 1, j, r, c);
    mark(A, vis, i - 1, j, r, c);
    mark(A, vis, i, j + 1, r, c);
    mark(A, vis, i, j - 1, r, c);
}
int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int> > vis(n, vector<int> (m));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'X') {
                if (not vis[i][j]) {
                    cnt++;
                    mark(A, vis, i, j, n, m);
                }
            }
        }
    }
    return cnt;
}