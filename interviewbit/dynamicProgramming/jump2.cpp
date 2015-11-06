int Solution::jump(vector<int> &A) {
    int n = A.size();
    if (n == 1) {
        return 0;
    }
    int ret = 1;
    int lim = A[0], tmp = A[0];
    for (int i = 0; i <= lim; i++) {
        if (i == n - 1) {
            return ret;
        }
        tmp = max(tmp, i + A[i]);
        if (i == lim) {
            if (i >= tmp) {
                return -1;
            }
            lim = tmp, ret++;
        }
    }
    return -1;
}