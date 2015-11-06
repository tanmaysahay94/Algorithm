bool isZero(string& A) {
    for (int i = 0; i < (int) A.size(); i++) {
        if (A[i] != '0') {
            return false;
        }
    }
    return true;
}
string clean(string& A) {
    if (isZero(A)) {
        return string("0");
    }
    int i = 0;
    while (i < (int) A.size() and A[i] == '0') {
        i++;
    }
    return A.substr(i);
}
string add(string& A, string& B) {
    if (A.size() < B.size()) {
        swap(A, B);
    }
    string ret(A.size() + 1, '0');
    A = string("0") + A;
    while (B.size() < A.size()) {
        B = string("0") + B;
    }
    int carry = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        int d1 = A[i] - '0';
        int d2 = B[i] - '0';
        int sum = d1 + d2 + carry;
        ret[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    return clean(ret);
}
string mul(string& A, int dig) {
    if (dig == 0) {
        return string("0");
    }
    string ret(A.size() + 1, '0');
    A = string("0") + A;
    int carry = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        int v = A[i] - '0';
        int put = dig * v + carry;
        ret[i] = (put % 10) + '0';
        carry = put / 10;
    }
    return clean(ret);
}
string Solution::multiply(string A, string B) {
    A = clean(A);
    B = clean(B);
    string ret = string("0");
    if (A.size() < B.size()) {
        swap(A, B);
    }
    for (int i = B.size() - 1, nzeros = 0; i >= 0; i--, nzeros++) {
        int dig = B[i] - '0';
        string prod = mul(A, dig);
        for (int j = 0; j < nzeros; j++) {
            prod.push_back('0');
        }
        ret = add(ret, prod);
    }
    return clean(ret);
}
