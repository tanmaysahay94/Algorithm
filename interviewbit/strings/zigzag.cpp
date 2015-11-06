string Solution::convert(string A, int B) {
    if (B == 1) {
        return A;
    }
    vector<string> v(B);
    int dir = 1;
    int curr = 0;
    for (int i = 0; i < (int) A.length(); i++) {
        v[curr].push_back(A[i]);
        if (curr == 0 and dir == -1) {
            dir *= -1;
        }
        else if (curr == B - 1 and dir == 1) {
            dir *= -1;
        }
        curr += dir;
    }
    string ret;
    for (int i = 0; i < B; i++) {
        ret += v[i];
    }
    return ret;
}
