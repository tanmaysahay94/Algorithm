int Solution::romanToInt(string A){ 
    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    if ((int) A.size() == 1) {
        return mp[A[0]];
    }
    int ans = 0;
    for (int i = 0, j = 1; j < (int) A.size(); i++, j++) {
        int v1 = mp[A[i]];
        int v2 = mp[A[j]];
        if (v1 >= v2) {
            ans += v1;
        }
        else {
            ans -= v1;
        }
    }
    ans += mp[A[A.size() - 1]];
    return ans;
}
