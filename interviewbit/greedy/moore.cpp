int Moore(const vector<int>& A) {
    int idx = 0, cnt = 1;
    for (int i = 0; i < (int) A.size(); i++) {
        if (A[idx] == A[i]) {
            cnt++;
        }
        else {
            cnt--;
        }
        if (!cnt) {
            idx = i;
            cnt = 1;
        }
    }
    return A[idx];
}
int Solution::majorityElement(const vector<int> &A) {
    return Moore(A);
}