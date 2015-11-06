int Solution::colorful(int A) {
    vector<int> v;
    int a(A);
    while (a) {
        v.push_back(a % 10);
        a /= 10;
    }
    unordered_map<int, pair<int, int> > ump;
    vector<int> p;
    int prod = 1;
    p.push_back(prod);
    for (int i = 0; i < (int) v.size(); i++) {
        prod *= v[i];
        p.push_back(prod);
        if (!prod) {
            return false;
        }
    }
    for (int i = 0; i < (int) v.size(); i++) {
        for (int j = i; j < (int) v.size(); j++) {
            pair<int, int> pii = make_pair(i, j);
            int val = p[j + 1] / p[i];
            ump[val] = pii;
        }
    }
    int n = v.size();
    return ((int) ump.size() == (n * (n + 1)) / 2);
}
