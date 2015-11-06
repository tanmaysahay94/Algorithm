vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ret;
    if (B > (int) A.size()) {
        return ret;
    }
    unordered_map<int, int> u_map;
    for (int i = 0; i + 1 < B; i++) {
        u_map[A[i]]++;
    }
    for (int i = B - 1; i < (int) A.size(); i++) {
        u_map[A[i]]++;
        ret.push_back(u_map.size());
        u_map[A[i - B + 1]]--;
        if (u_map[A[i - B + 1]] == 0) {
            u_map.erase(A[i - B + 1]);
        }
    }
    return ret;
}
