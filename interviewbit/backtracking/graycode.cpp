void solve(vector<int> &ret, int cnt){
    if (cnt == 1) {
        ret.push_back(0);
        ret.push_back(1);
        return;
    }
    solve(ret, cnt - 1);
    for (int i = ret.size() - 1; i >= 0; i--) {
        ret.push_back(ret[i] | (1 << (cnt - 1)));
    }
}
vector<int> Solution::grayCode(int A) {
    vector<int> ret;
    if (not A) {
        ret.push_back(0);
        return ret;
    }
    solve(ret, A);
    return ret;
}
