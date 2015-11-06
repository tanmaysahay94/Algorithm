int Solution::braces(string A) {
    stack<char> S;
    bool redundance = false;
    for (auto a: A) {
        if (a != ')') {
            S.push(a);
        }
        else {
            if (not S.size()) {
                continue;
            }
            if (S.top() == '(') {
                S.pop();
                redundance = true;
                break;
            }
            else {
                int opCount = 0;
                while (S.size() and S.top() != '(') {
                    opCount += (S.top() == '+' or S.top() == '-' or S.top() == '/' or S.top() == '*');
                    S.pop();
                }
                if (S.size() and S.top() == '(') {
                    S.pop();
                }
                if (not opCount) {
                    redundance = true;
                    break;
                }
            }
        }
    }
    return redundance;
}
