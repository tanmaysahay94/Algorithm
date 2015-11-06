vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    unordered_map<int, vector<pair<int, int> > >u_map;
    for (int i = 0; i < (int) A.size(); i++) {
        for (int j = i + 1; j < (int) A.size(); j++) {
            u_map[A[i] + A[j]].push_back(make_pair(i, j));
        }
    }
    vector<int> row(4);
    set<vector<int> > _ret;
    unordered_map<int, vector<pair<int, int> > >::iterator u;
    while (u_map.size()) {
        u = u_map.begin();
        int val = u -> first;
        if (u_map.find(B - val) != u_map.end()) {
            for (int i = 0; i < (int) u -> second.size(); i++) {
                for (int j = 0; j < (int) u_map[B - val].size(); j++) {
                    if (u -> second[i].first != u_map[B - val][j].first and u -> second[i].first != u_map[B - val][j].second and u -> second[i].second != u_map[B - val][j].first and u -> second[i].second != u_map[B - val][j].second)  {
                        row[0] = A[u -> second[i].first];
                        row[1] = A[u -> second[i].second];
                        row[2] = A[u_map[B - val][j].first];
                        row[3] = A[u_map[B - val][j].second];
                        sort(row.begin(), row.end());
                        _ret.insert(row);
                    }
                }
            }
        }
        u_map.erase(u);
    }
    vector<vector<int> > ret;
    for (auto r: _ret) {
        ret.push_back(r);
    }
    sort(ret.begin(), ret.end());
    return ret;
}
