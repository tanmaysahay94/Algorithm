bool isNum(char a) {
    return (a >= '0' and a <= '9');
}
int Solution::atoi(const string &A) {
    int len = A.length();
    int i = 0;
    while (i < len and not isNum(A[i])) {
        i++;
    }
    int j = i;
    while (j < len and isNum(A[j])) {
        j++;
    }
    if (i == len) {
        return 0;
    }/*
    if (j < len) {
        if (A[j] != ' ') {
            return 0;
        }
    }*/
    bool neg = false;
    int s_idx;
    if (i > 0) {
        if (A[i - 1] == '-') {
            neg = true;
            for (int idx = 0; idx < i - 1; idx++) {
                if (A[idx] != ' ') {
                    return 0;
                }
            }
        }
        else if (A[i - 1] == '+') {
            for (int idx = 0; idx < i - 1; idx++) {
                if (A[idx] != ' ') {
                    return 0;
                }
            }
        }
        else {
            for (int idx = 0; idx < i; idx++) {
                if (A[idx] != ' ') {
                    return 0;
                }
            }
        }
    }
    __int128_t ans = 0;
    for (int idx = i; idx < j; idx++) {
        ans = 10 * ans + A[idx] - '0';
    }
    if (neg) {
        ans = -ans;
    }
    if (ans > INT_MAX) {
        return INT_MAX;
    }
    if (ans < INT_MIN) {
        return INT_MIN;
    }
    return (int) ans;
}
