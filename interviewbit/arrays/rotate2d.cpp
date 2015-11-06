void solve(vector<vector<int> >& B, int row, int col, int lim) {
    for (int i = 0; i < lim / 2; i++) {
        swap(B[row][col + i], B[row][col + lim - i - 1]);
    }
    for (int i = 0; i < lim / 2; i++) {
        swap(B[row + lim - 1][col + i], B[row + lim - 1][col + lim - i - 1]);
    }
    for(int i = 0; i < lim; i++) {
		swap(B[row][col + i], B[row + lim - 1 - i][col + lim - 1]);
    }
    for(int i = 0; i < lim; i++) {
		swap(B[row + i][col], B[row + lim - 1][col + lim - 1 - i]);
    }
    swap(B[row][col], B[row + lim - 1][col + lim - 1]);
    for(int i = 1; i < lim - 1; i++)
		swap(B[row][col + i], B[row + lim - 1][col + i]);
}
void Solution::rotate(vector<vector<int> > &B) {
    int n = B.size();
    for (int i = 0; i < n / 2; i++) {
        solve(B, i, i, n - (i << 1));
    }
}