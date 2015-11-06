int Solution::singleNumber(const vector<int> &A){ 
    vector<int> cnt(32);
    for (int i = 0; i < (int) A.size(); i++) {
        int v = A[i];
        if (v < 0) {
            cnt[31]++;
        }
        for (int j = 0; j < 31; j++) {
            cnt[j] += (v & 1);
            v >>= 1;
        }
    }
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        ans <<= 1;
        ans |= (cnt[i] % 3 == 1);
    }
    if (cnt[31]) {
        ans = -ans;
    }
    return ans;
}
