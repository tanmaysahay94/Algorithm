string Solution::fractionToDecimal(int numerator, int denominator) {
    string ret = "";
    long long nume = numerator;
    long long deno = denominator;
    long long q, neg = 0;
    if (nume < 0) {
        nume = -nume;
        neg = 1;
    }
    if (deno < 0) {
        deno = -deno;
        neg ^= 1;
    }
    if (nume == 0) {
        ret += '0';
        return ret;
    }
    if (neg) {
        ret += '-';
    }
    q = nume / deno;
    ret.append(to_string(q));
    if (nume % deno == 0) {
        return ret;
    }
    ret.append(".");
    bool rep = false;
    int len = ret.size();
    unordered_map<int, int> u_map;
    nume %= deno;
    while (nume > 0 and not rep) {
        nume *= 10;
        if (u_map.count(nume)) {
            len = u_map[nume];
            rep = 1;
            break;
        }
        else {
            u_map[nume] = ret.size();
        }
        q = nume / deno;
        ret.append(to_string(q));
        nume %= deno;
    }
    if (rep) {
        ret.append(")");
        ret.insert(len, "(");
    }
    return ret;
}
