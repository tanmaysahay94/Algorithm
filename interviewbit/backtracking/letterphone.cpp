vector<string> Solution::letterCombinations(string A) {
    map<char, string> mp;
    mp['1'] = string("1");
    mp['0'] = string("0");
    mp['2'] = string("abc");
    mp['3'] = string("def");
    mp['4'] = string("ghi");
    mp['5'] = string("jkl");
    mp['6'] = string("mno");
    mp['7'] = string("pqrs");
    mp['8'] = string("tuv");
    mp['9'] = string("wxyz");
    vector<string> ret;
    for (auto s: mp[A[0]]) {
        string foo;
        foo.push_back(s);
        ret.push_back(foo);
    }
    for (int i = 1; A[i]; i++) {
        vector<string> foo;
        for (auto s: mp[A[i]]) {
            for (auto &r: ret) {
                string bar = r;
                bar.push_back(s);
                foo.push_back(bar);
            }
        }
        ret = foo;
    }
    sort(ret.begin(), ret.end());
    return ret;
}
