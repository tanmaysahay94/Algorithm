int Solution::compareVersion(string A, string B) {
    int m = A.length(), n = B.length();
    int i = 0, j = 0;
    while (i < m and j < n) {
        int ii = i, jj = j;
        string a, b;
        while (ii < m and A[ii] != '.') {
            a.push_back(A[ii]);
            ii++;
        }
        ii++;
        while (jj < n and B[jj] != '.') {
            b.push_back(B[jj]);
            jj++;
        }
        jj++;
        if (a.length() > b.length()) {
            b = string(a.length() - b.length(), '0') + b;
        }
        else if (b.length() > a.length()) {
            a = string(b.length() - a.length(), '0') + a;
        }
        if (a > b) {
            return 1;
        }
        if (a < b) {
            return -1;
        }
        i = ii;
        j = jj;
    }
    if (i >= m and j >= n) {
        return 0;
    }
    if (i >= m) {
        int jj = j;
        bool is_same = true;
        for (; jj < n and is_same; jj++) {
            is_same = is_same and (B[jj] == '.' or B[jj] == '0');
        }
        if (is_same) {
            return 0;
        }
        return -1;
    }
    if (j >= n) {
        int ii = i;
        bool is_same = true;
        for (; ii < m and is_same; ii++) {
            is_same = is_same and (A[ii] == '.' or A[ii] == '0');
        }
        if (is_same) {
            return 0;
        }
        return 1;
    }
    return 0;
}
