bool isZero(string& s) {
    bool ret = true;
    for (int i = 0; i < (int) s.length() and ret; i++) {
        if (s[i] != '0') {
            ret = false;
        }
    }
    return ret;
}

bool smartCmp(const string& a, const string& b) {
    return a + b > b + a;
}

string sanitize(string S) {
    if (isZero(S)) {
        return string("0");
    }
    int idx = 0;
    while (idx < (int) S.size() and S[idx] == '0') {
        idx++;
    }
    return S.substr(idx);
}

string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = to_string(A[i]);
    }
    sort(v.begin(), v.end(), smartCmp);
    string ret;
    for (auto V: v) {
        ret += V;
    }
    return sanitize(ret);
}
