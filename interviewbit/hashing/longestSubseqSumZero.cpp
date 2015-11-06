vector<int> Solution::lszero(vector<int> &A) {
    vector<int> pre(A.size() + 1);
    pre[0] = 0;
    for (int i = 0; i < (int) A.size(); i++) {
        pre[i + 1] = pre[i] + A[i];
    }
    unordered_map<int, vector<int> > U_MP;
    for (int i = 0; i < (int) pre.size(); i++) {
        U_MP[pre[i]].push_back(i);
    }
    int len = INT_MIN, s, e;
    for (auto u: U_MP) {
        int s_s = *(u.second.begin()) + 1;
        int s_e = *(u.second.rbegin());
        int s_l = s_e - s_s + 1;
        if (s_l > len or (s_l == len and s_s < s)) {
            len = s_l, s = s_s, e = s_e;
        }
    }
    vector<int> ans;
    for (int i = s - 1; i <= e - 1; i++) {
        ans.push_back(A[i]);
    }
    return ans;
}
