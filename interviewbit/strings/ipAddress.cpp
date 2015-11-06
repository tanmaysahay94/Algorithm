bool inRange(int val) {
    return 0 <= val and val < 256;
}

vector<string> Solution::restoreIpAddresses(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> valid;
    int n = A.size();
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j + 1 < n and j <= i + 3; j++) {
            for (int k = j + 1; k + 1 < n and k <= j + 3; k++) {
                int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
                int prev = -1;
                for (int idx = 0; idx <= i; idx++) {
                    if (prev != v1) {
                        prev = v1;
                        v1 = 10 * v1 + A[idx] - '0';
                    }
                    else {
                        v1 = 1000;
                        break;
                    }
                }
                prev = -1;
                for (int idx = i + 1; idx <= j; idx++) {
                    if (prev != v2) {
                        prev = v2;
                        v2 = 10 * v2 + A[idx] - '0';
                    }
                    else {
                        v2 = 1000;
                        break;
                    }
                }
                prev = -1;
                for (int idx = j + 1; idx <= k; idx++) {
                    if (prev != v3) {
                        prev = v3;
                        v3 = 10 * v3 + A[idx] - '0';
                    }
                    else {
                        v3 = 1000;
                        break;
                    }
                }
                prev = -1;
                for (int idx = k + 1; idx < n; idx++) {
                    if (prev != v4) {
                        prev = v4;
                        v4 = 10 * v4 + A[idx] - '0';
                    }
                    else {
                        v4 = 1000;
                        break;
                    }
                }
                if (inRange(v1) and inRange(v2) and inRange(v3) and inRange(v4)) {
                    int idx = 0;
                    string s;
                    for (; idx <= i; idx++) {
                        s.push_back(A[idx]);
                    }
                    s.push_back('.');
                    for (; idx <= j; idx++) {
                        s.push_back(A[idx]);
                    }
                    s.push_back('.');
                    for (; idx <= k; idx++) {
                        s.push_back(A[idx]);
                    }
                    s.push_back('.');
                    for (; idx < n; idx++) {
                        s.push_back(A[idx]);
                    }
                    valid.push_back(s);
                }
            }
        }
    }
    return valid;
}
