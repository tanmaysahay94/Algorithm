vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int> > ret;
    for (int i = 0; i < (int) A.size(); i++) {
        int col = i;
        int row = 0;
        vector<int> tmp;
        while (col >= 0) {
            tmp.push_back(A[row][col]);
            col--;
            row++;
        }
        ret.push_back(tmp);
    }
    for (int i = 1; i < (int) A.size(); i++) {
        int row = i;
        int col = A.size() - 1;
        vector<int> tmp;
        while (row < (int) A.size()) {
            tmp.push_back(A[row][col]);
            row++;
            col--;
        }
        ret.push_back(tmp);
    }
    return ret;
}
