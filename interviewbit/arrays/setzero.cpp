void Solution::setZeroes(vector<vector<int> > &A) {
    set<int> row, col;
    for (int i = 0; i < (int) A.size(); i++) {
        for (int j = 0; j < (int) A[i].size(); j++) {
            if (A[i][j] == 0) {
                row.insert(i);
                col.insert(j);
            }
        }
    }
    set<int>::iterator it;
    for (it = row.begin(); it != row.end(); it++) {
        for (int j = 0; j < (int) A[*it].size(); j++) {
            A[*it][j] = 0;
        }
    }
    for (it = col.begin(); it != col.end(); it++) {
        for (int j = 0; j < (int) A.size(); j++) {
            A[j][*it] = 0;
        }
    }
}
