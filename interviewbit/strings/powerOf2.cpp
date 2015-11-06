bool not_one(string N) {
    int sz = N.size();
    if (sz > 1) {
        return 1;
    }
    return N[0] != '1';
}

bool is_even(string N) {
    int dig = (N[N.size() - 1] - '0') & 1;
    return (!dig);
}

string divide(string N, int d) {
    reverse(N.begin(), N.end());
    long long base = 10;
    string temp = "";
    for (int i = (int) N.size() - 1, rem = 0; i >= 0; i--) {
        long long cur = (N[i] - '0') + rem * base;
        int val = cur / d;
        rem = cur % d;
        temp += val + '0';
    }
    while (temp.size() and !(temp[0] - '0')) {
        temp.erase(temp.begin());
    }
    return temp;
}
int Solution::power(string N) {
    int sz = N.size();
    if (sz == 1) {
        if (N[0] == '2' or N[0] == '4' or N[0] == '8') {
            return 1;
        }
        return 0;
    }
    while (not_one(N) and is_even(N)) {
        N = divide(N, 2);
        if (N.size() == 1 and N[0] == '1') {
            break;
        }
    }
    if (not_one(N)) {
        return 0;
    }
    return 1;
}