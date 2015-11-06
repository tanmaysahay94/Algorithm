vector<vector<int> > Solution::generate(int A) {
    vector<vector<int> > sol;
    if (A == 0) {
        return sol;
    }
    vector<int> tmp; tmp.push_back(1);
    sol.push_back(tmp);
    for (int i = 1; i < A; i++) {
        vector<int> foo;
        foo.push_back(1);
        for (int j = 1; j < (int) sol[i - 1].size(); j++) {
            foo.push_back(sol[i - 1][j] + sol[i - 1][j - 1]);
        }
        foo.push_back(1);
        sol.push_back(foo);
    }
    return sol;
}
