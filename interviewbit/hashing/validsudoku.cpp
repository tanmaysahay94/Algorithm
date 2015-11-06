int Solution::isValidSudoku(const vector<string> &A) {
    int row[9][9], col[9][9], cel[9][9];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(cel, 0, sizeof(cel));
    for (int r = 0; r < 9; r++) {
        for (auto c: A[r]) {
            if (c >= '0' and c <= '9') {
                row[r][c - '0']++;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = A[j][i];
            if (c >= '0' and c <= '9') {
                col[i][c - '0']++;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int celNo = 3 * (i / 3) + j / 3;
            char c = A[i][j];
            if (c >= '0' and c <= '9') {
                cel[celNo][c - '0']++;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (row[i][j] > 1 or col[i][j] > 1 or cel[i][j] > 1) {
                return false;
            }
        }
    }
    return true;
}
