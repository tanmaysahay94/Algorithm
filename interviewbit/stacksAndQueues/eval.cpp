int stoi(string& S) {
    bool neg = false;
    if (S[0] == '-') {
        neg = true;
    }
    int ret = 0;
    int idx = 0;
    idx += neg;
    for (; idx < (int) S.size(); idx++) {
        char s = S[idx];
        ret = 10 * ret + s - '0';
    }
    if (neg) {
        ret *= -1;
    }
    return ret;
}
bool isOperator(string& S) {
    if (S.size() > 1) {
        return false;
    }
    return (S[0] == '+' or S[0] == '-' or S[0] == '*' or S[0] == '/');
}
int Solution::evalRPN(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int ans = 0;
    stack<int> S;
    for (auto a: A) {
        if (isOperator(a)) {
            int v1 = S.top();
            S.pop();
            int v2 = S.top();
            S.pop();
            if (a[0] == '+') {
                v2 += v1;
            }
            else if (a[0] == '-') {
                v2 -= v1;
            }
            else if (a[0] == '*') {
                v2 *= v1;
            }
            else if (a[0] == '/') {
                v2 /= v1;
            }
            S.push(v2);
        }
        else {
            S.push(stoi(a));
        }
    }
    assert((int)S.size() == 1);
    return S.top();
}
