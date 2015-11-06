int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_multiset<int> u_mset;
    for (auto a: A) {
        u_mset.insert(a);
    }
    for (auto u: u_mset) {
        if ((B and u_mset.count(u + B)) or (!B and u_mset.count(u) > 1)) {
            return 1;
        }
    }
    return 0;
}
