string Solution::addBinary(string A, string B) {
    int lena = A.length();
    int lenb = B.length();
    if (lena < lenb) {
        int diff = lenb - lena;
        string v(diff, '0');
        A = v + A;
    }
    else if (lena > lenb) {
        int diff = lena - lenb;
        string v(diff, '0');
        B = v + B;
    }
    A = string("0") + A;
    B = string("0") + B;
    int len = A.length();
    int carry = 0;
    for (int i = len - 1; i >= 0; i--) {
        int sum = carry + (A[i] - '0') + (B[i] - '0');
        if (sum == 2 or sum == 3) {
            carry = 1;
        }
        else if (sum == 0 or sum == 1) {
            carry = 0;
        }
        sum &= 1;
        A[i] = sum + '0';
    }
    int idx = 0;
    while (A[idx] == '0') {
        idx++;
    }
    if (idx == (int) A.length()) {
        return string("0");
    }
    return A.substr(idx);
}
