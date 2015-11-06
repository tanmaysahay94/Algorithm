const int mod = 1e9 + 7;

int getHash(vector<int>& v) {
    int val = 0;
    for (int i = 0; i < (int) v.size(); i++) {
        val = 26 * val + v[i];
        val %= mod;
    }
    return val;
}
vector<int> rep(string S) {
    vector<int> v(26);
    for (auto s: S) {
        v[s - 'a']++;
    }
    return v;
}
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<int, vector<int> > u_map;
    vector<int> tmp;
    int hash;
    for (int i = 0; i < (int) A.size(); i++) {
        tmp = rep(A[i]);
        hash = getHash(tmp);
        u_map[hash].push_back(i + 1);
    }
    vector<vector<int> > ret;
    for (auto u: u_map) {
        ret.push_back(u.second);
    }
    return ret;
}
