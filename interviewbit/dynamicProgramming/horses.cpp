long long solve(vector<vector<int> >&, string, int, int);
long long store(vector<vector<int> >&, string, int, int);

long long prod(string S) {
    long long w = 0, b = 0;
    for (auto s: S) {
        if (s == 'W') {
            w++;
        }
        else {
            b++;
        }
    }
    return w * b;
}

long long store(vector<vector<int> >& V, string A, int start, int part) {
    if (V[start][part] >= 0) {
        return V[start][part];
    }
    V[start][part] = solve(V, A, start, part);
    return V[start][part];
}

long long solve(vector<vector<int> >& V, string A, int start, int part) {
    int n = A.size();
    long long ret = INT_MAX;
    if (part == 0) {
        return prod(A.substr(start, n - start));
    }
    for (int i = start; i < n - part; i++) {
        ret = min(ret, prod(A.substr(start, i - start + 1)) + store(V, A, i + 1, part - 1));
    }
    return ret;
}

int Solution::arrange(string A, int B) {
    int n = A.size();
    if (B > n) {
        return -1;
    }
    vector<vector<int> > V(n, vector<int> (B, -1));
    long long answer = solve(V, A, 0, B - 1);
    return ((int) answer);
}