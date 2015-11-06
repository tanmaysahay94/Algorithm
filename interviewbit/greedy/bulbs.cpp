int Solution::bulbs(vector<int> &A) {
    int cnt = 0;
    int n = A.size();
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr += A[i];
    }
    for (int i = 0; i < n; i++) {
        A[i] ^= (cnt & 1);
        if (A[i]) {
            continue;
        }
        cnt++;  // switch it on
        curr++; // switch current bulb on
        /*
        int left = i;
        int right = n - i - 1;
        int tmp = curr - left - 1;
        tmp = right - tmp;
        curr = left + 1 + tmp;
        */
        curr = n - curr + i + 1;
        if (curr == n) {
            break;
        }
    }
    return cnt;
}
