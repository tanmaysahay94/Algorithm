bool in1(char c) {
    return c <= '9' and c > '0';
}
int Solution::numDecodings(string A) {
    int p, q;
    int ans;
    int i;
    int n = A.size();
    if (n == 1) {
        if(in1(A[i])) {
            return 1;
        }
        return false;
    }
    if (in1(A[0])) {
        q = 1;
    }
    else {
        return 0;
    }
    if (A[0] == '1') {
        if(in1(A[1])) {
            p = 2;
        }
        else {
            p = 1;
        }
    }
    else if (A[0] == '2') {
        if(A[1]-'0' > 0 and A[1] - '0' <= 6) {
            p = 2;
        }
        else {
            p = 1;
        }
    }
    else {
        p = 1;
    }
    if (n == 2) {
        return p;
    }
    i = 2;
    while (i < n) {
        if (A[i] == '0') {
            if(A[i - 1] == '1' or A[i - 1] == '2') {
                ans = q;
                p = ans;
            } 
            else {
                return 0;
            }
        } 
        else if (in1(A[i])) {
            if(A[i - 1] == '1' or (A[i - 1] == '2' and A[i] - '0' <= 6)) {
                ans = p + q;
            }
            else {
                ans = p;
            }
            q = p;
            p = ans;
        }
        i++;
    }
    return ans;
}