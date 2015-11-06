string Solution::longestCommonPrefix(vector<string> &A) {
    vector<int> ptr(A.size());
    string ret;
    bool inProgress = true;
    int mn = INT_MAX;
    for (int i = 0; i < (int) A.size(); i++) {
        mn = min(mn, (int) A[i].length());
    }
    for (int i = 0; i < mn and inProgress; i++) {
        char c = A[0][i];
        for (int j = 1; j < (int) A.size() and inProgress; j++) {
            if (A[j][i] != c) {
                inProgress = false;
            }
        }
        if (inProgress) {
            ret += c;
        }
    }
    return ret;
}
