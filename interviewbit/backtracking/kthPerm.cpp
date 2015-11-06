vector<int> F(15);
int lim = 13;
void init() {
    F[0] = 1;
    for (int i = 1; i <= 12; i++) {
        F[i] = i * F[i - 1];
    }
}
void solve(deque<int>& D, string& ret, int n, int k) {
    if (D.empty()) {
        return;
    }
    auto d = D.begin();
    while (F[n - 1] < k) {
        k -= F[n - 1];
        d++;
    }
    ret.append(to_string(*d));
    D.erase(d);
    solve(D, ret, n - 1, k);
}
string Solution::getPermutation(int n, int k) {
    init();
    deque<int> D;
    for (int i = 1; i <= n; i++) {
        D.push_back(i);
    }
    auto d = D.begin();
    string ret = "";
    while (n > lim) {
        ret.append(to_string(*d));
        n--;
        D.pop_front();
        d = D.begin();
    }
    solve(D, ret, n, k);
    return ret;
}
