int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ret = INT_MIN;
    for (int i = 0; i < (int) A.size(); i++) {
        ret = max(ret, abs(A[i] - B[i]));
    }
    return ret;
}