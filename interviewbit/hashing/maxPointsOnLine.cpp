int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int ans = 0;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        int curr = 0, samex = 0, samexy = 0;
        map<pair<int, int>, int> cnt;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (A[i] == A[j] and B[i] == B[j]) {
                samexy++;
                continue;
            }
            if (A[i] == A[j]) {
                samex++;
                curr = max(curr, samex);
                continue;
            }
            int xd = A[i] - A[j];
            int yd = B[i] - B[j];
            int gcd = __gcd(xd, yd);
            pair<int, int> p = make_pair(yd / gcd, xd / gcd);
            cnt[p]++;
            curr = max(curr, cnt[p]);
        }
        ans = max(ans, curr + samexy + 1);
    }
    return ans;
}