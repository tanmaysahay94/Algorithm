int Solution::threeSumClosest(vector<int> &A, int b) {
    long long B = b;
    sort(A.begin(), A.end());
    long long bestSol = INT_MAX;
    for (int i = 0; i < A.size() - 2; i++) {
        int l = i + 1;
        int r = A.size() - 1;
        while (l < r) {
            if (A[i] + A[l] + A[r] == B) {
                return B;
            }
            long long s = A[i] + A[l] + A[r];
            if (abs(B - s) < abs(B - bestSol)) {
                bestSol = s;
            }
            if (s < B) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    return bestSol;
}
