vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int, vector<int> > mp;
    for (int i = 0; i < (int) A.size(); i++) {
        mp[A[i]].push_back(i);
    }
    vector<int> ret;
    int idx1 = 0, idx2 = INT_MAX;
    for (int i = 0; i < (int) A.size(); i++) {
        int foo = B - A[i];
        if (mp.find(foo) != mp.end()) {
            idx1 = idx2 = i;
            int j = 0;
            while (j < (int) mp[foo].size()) {
                if (mp[foo][j] != i) {
                    idx2 = mp[foo][j];
                    j = mp[foo].size();
                }
                j++;
            }
            if (idx1 < idx2) {
                if (ret.empty()) {
                    ret.push_back(idx1);
                    ret.push_back(idx2);
                }
                else if (idx2 < ret[1]) {
                    ret[1] = idx2;
                    ret[0] = idx1;
                }
            }
        }
    }
    if (ret.size()) {
        ret[0]++, ret[1]++;
    }
    return ret;
}
