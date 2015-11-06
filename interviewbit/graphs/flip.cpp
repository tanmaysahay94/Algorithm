void process(vector<vector<char> > &A, queue<pair<int, int> > &Q, int r, int c) {
    int n = A.size();
    int m = A[0].size();
    if (r < 0 or c < 0 or r >= n or c >= m) {
        return;
    }
    if (A[r][c] != 'O') {
        return;
    }
    A[r][c] = '$';
    Q.push(make_pair(r, c));
}
void mark(vector<vector<char> > &A, int r, int c) {
    int n = A.size();
    queue<pair<int, int> > Q;
    process(A, Q, r, c);
    while (Q.size()) {
        pair<int, int> p = Q.front();
        Q.pop();
        int row = p.first, col = p.second;
        process(A, Q, row, col - 1);
        process(A, Q, row, col + 1);
        process(A, Q, row - 1, col);
        process(A, Q, row + 1, col);
    }
}
void Solution::solve(vector<vector<char> > &A) {
    if (A.size() == 0) {
        return;
    }
    int n = A.size();
    int m = A[0].size();
    for (int row = 0; row < n; row++) {
        if (A[row][0] == 'O') {
            mark(A, row, 0);
        }
        if (A[row][m - 1] == 'O') {
            mark(A, row, m - 1);
        }
    }
    for (int col = 0; col < m; col++) {
        if (A[0][col] == 'O') {
            mark(A, 0, col);
        }
        if (A[n - 1][col] == 'O') {
            mark(A, n - 1, col);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'O') {
                A[i][j] = 'X';
            }
            else if (A[i][j] == '$') {
                A[i][j] = 'O';
            }
        }
    }
}