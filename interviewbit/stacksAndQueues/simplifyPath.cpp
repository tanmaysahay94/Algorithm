void sanitize(string& A) {
    int idx = 0;
    while (idx < (int) A.size() and A[idx] == '/') {
        idx++;
    }
    A = A.substr(idx);
}
vector<string> process(string& A) {
    vector<string> ret;
    string word;
    int i = 0;
    for (auto a: A) {
        if (a == '/') {
            if (not i) {
                continue;
            }
            sanitize(word);
            if (word.size()) {
                ret.push_back(word);
            }
            word = string("");
        }
        else {
            word.push_back(a);
        }
        i++;
    }
    if (A[A.size() - 1] != '/') {
        ret.push_back(word);
    }
    return ret;
}
string Solution::simplifyPath(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> path = process(A);
    stack<string> S;
    for (auto p: path) {
        if (p == string(".")) {
            continue;
        }
        else if (p == string("..")) {
            if (S.size()) {
                S.pop();
            }
        }
        else {
            S.push(p);
        }
    }
    if (S.size() == 0) {
        return string("/");
    }
    path.resize(0);
    while (S.size()) {
        path.push_back(S.top());
        S.pop();
    }
    string ret;
    for (int i = path.size() - 1; i >= 0; i--) {
        ret.push_back('/');
        ret += path[i];
    }
    return ret;
}
