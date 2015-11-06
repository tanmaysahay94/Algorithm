vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int, vector<pair<int, int> > >u_map;
    for (int i = 0; i < (int) A.size(); i++) {
        for (int j = i + 1; j < (int) A.size(); j++) {
            u_map[A[i] + A[j]].push_back(make_pair(i, j));
        }
    }
    bool done = false;
    vector<int> ret(4);
    for (auto u: u_map) {
        int val = u.first;
        vector<int> tmp(4);
        vector<pair<int, int> > foo = u.second;
        if (foo.size() < 2) {
            continue;
        }
        tmp[0] = foo[0].first, tmp[1] = foo[0].second;
        for (int i = 1; i < (int) foo.size(); i++) {
            if (foo[i].first > tmp[0] and foo[i].first != tmp[1] and foo[i].second > tmp[1]) {
                tmp[2] = foo[i].first, tmp[3] = foo[i].second;
                if (not done) {
                    done = true;
                    ret = tmp;
                }
                else {
                    if (tmp[0] < ret[0] or (tmp[0] == ret[0] and tmp[1] < ret[1]) or (tmp[0] == ret[0] and tmp[1] == ret[1] and tmp[2] < ret[2]) or (tmp[0] == ret[0] and tmp[1] == ret[1] and tmp[2] == ret[2] and tmp[3] < ret[3])) {
                        ret = tmp;
                    }
                }
                break;
            }
        }
    }
    if (not done) {
        ret.resize(0);
    }
    return ret;
}
