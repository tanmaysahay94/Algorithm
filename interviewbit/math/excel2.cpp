string Solution::convertToTitle(int A) {
    string ret;
    map<int, char> mp;
    for (int i = 1; i < 26; i++) {
        mp[i] = i - 1 + 'A';
    }
    mp[0] = 'Z';
    while (A) {
        ret += mp[A % 26];
        if (A % 26 == 0) {
            A--;
        }
        A /= 26;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
