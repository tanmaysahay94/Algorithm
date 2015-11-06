vector<int> Solution::maxset(vector<int> &A) {
    long long start, end, sum = 0;
    long long ansSum = LLONG_MIN, ansStart = -1, ansEnd = -1;
    int i = 0;
    while (i < (int) A.size()) {
        if (A[i] >= 0) {
            start = i;
            while (i < (int) A.size() and A[i] >= 0) {
                sum += A[i];
                i++;
            }
            end = i - 1;
            if (sum > ansSum) {
                ansSum = sum;
                ansStart = start;
                ansEnd = end;
            }
            else if (sum == ansSum) {
                if (end - start > ansEnd - ansStart) {
                    ansSum = sum;
                    ansStart = start;
                    ansEnd = end;
                }
            }
			sum = 0;
        }
        else {
			sum = 0;
            i++;
        }
    }
    vector<int> ret;
    if (ansEnd > -1 and ansStart > -1) {
        for (int i = ansStart; i <= ansEnd; i++) {
            ret.push_back(A[i]);
        }
    }
    return ret;
}
