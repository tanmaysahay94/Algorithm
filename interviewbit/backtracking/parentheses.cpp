void solve(vector<string>& V, string s, int open, int close) {
    if (open > close) {
        return;
    }
    if (open == 0) {
        while (close--) {
            s.push_back(')');
        }
        V.push_back(s);
        return;
    }
    s.push_back('(');
    solve(V, s, open - 1, close);
    s.pop_back();
    s.push_back(')');
    solve(V, s, open, close - 1);
}
vector<string> Solution::generateParenthesis(int A) {
    vector<string> V;
    solve(V, string(""), A, A);
    sort(V.begin(), V.end());
    return V;
}
