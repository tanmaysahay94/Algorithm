int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> S;
    int n = A.size();
    int ret = 0;
    int idx = 0;
    while (idx < n) {
        int foo;
        if (S.empty()) {
            S.push(idx);
        }
        else {
            if (A[idx] >= A[S.top()]) {
                S.push(idx);
            }
            else {
                int s, e = idx;
                while (S.size() and A[idx] < A[S.top()]) {
                    foo = S.top();
                    S.pop();
                    if (S.empty()) {
                        s = -1;
                    }
                    else {
                        s = S.top();
                    }
                    ret = max(ret, (e - s - 1) * A[foo]);
                }
                S.push(idx);
            }
        }
        idx++;
    }
    int s, e = n;
    while (S.size()) {
        int foo = S.top();
        S.pop();
        if (S.empty()) {
            s = -1;
        }
        else {
            s = S.top();
        }
        ret = max(ret, (e - s - 1) * A[foo]);
    }
    return ret;
}
