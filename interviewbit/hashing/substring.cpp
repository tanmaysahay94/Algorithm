bool check(string s, unordered_map<string, pair<int, int> > u_map, int l, int m) {
    string tmp;
    int n = s.size();
    for (auto &u: u_map) {
        u.second.second = 0;
    }
    int i = 0, cnt = 0;
    while (i <= n - l) {
        tmp = s.substr(i, l);
        if (u_map.find(tmp) == u_map.end()) {
            return 0;
        }
        else {
            u_map[tmp].second++;
            if (u_map[tmp].second <= u_map[tmp].first) {
                cnt++;
            }
            else {
                return 0;
            }
        }
        i += l;
    }
    return (m == cnt);
}
vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    unordered_map <string, pair<int, int> > u_map;
    int n = A.size(), m = B.size(), l = B[0].size();
    for (int i = 0; i < m; i++) {
        u_map[B[i]].first++;
    }
    vector<int> ret;
    if (l * m > n) {
        return ret;
    }
    string s;
    int i = 0;
    while (i <= n - l * m){
        s = A.substr(i, l * m);
        if (check(s, u_map, l, m)) {
            ret.push_back(i);
        }
        i++;
    }
    return ret;
}