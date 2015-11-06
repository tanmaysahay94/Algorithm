vector<int> Solution::getRow(int A) {
    vector<int> ret;
    ret.push_back(1);
    for (int i = 1; i <= A; i++) {
        vector<int> tmp;
        tmp.push_back(1);
        for (int j = 1; j < (int) ret.size(); j++) {
            tmp.push_back(ret[j] + ret[j - 1]);
        }
        tmp.push_back(1);
        ret = tmp;
    }
    return ret;
}
