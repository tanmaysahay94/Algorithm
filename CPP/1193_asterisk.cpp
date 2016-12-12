
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cassert>
#include <utility>
#include <stack>
#include <cstdlib>
#include <set>
#include <unordered_map>
#include <climits>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename __Tp1>
void __f(const char* name, __Tp1&& __tp1){
    cerr << name << " : " << __tp1 << std::endl;
}
template <typename __Tp1, typename... __Tps>
void __f(const char* names, __Tp1&& __tp1, __Tps&&... __tps){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " <<  __tp1 << " | " ;
    __f(comma+1, __tps...);
}
#else
#define trace(...)
#endif

typedef long long LL;
const LL mod = 1e9 + 7;

LL fpm(LL a, LL b, LL m = mod) {
    LL ret = 1;
    while (b) {
        if (b & 1) {
            ret = (ret * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    ret %= m;
    if (ret < 0) ret += m;
    return ret;
}

LL mm(LL a, LL b, LL m = mod) {
    LL ret = a % m;
    ret *= b % m;
    ret %= m;
    if (ret < 0) ret += m;
    return ret;
}

LL add(LL a, LL b, LL m = mod) {
    LL ret = a % m;
    ret += b % m;
    ret %= m;
    if (ret < 0) ret += m;
    return ret;
}

bool isvalid(string &s) {
    int len = s.size();
    if (s[0] == '*' or s[len - 1] == '*') return false;
    int cnt = 0;
    for (auto &c: s)
        if (c != '*')
            cnt = 0;
        else {
            cnt++;
            if (cnt > 2) return false;
        }
    return true;
}

void solve() {
    string s;
    cin >> s;
    if (not isvalid(s)) {
        cout << "Syntax Error" << endl;
        return;
    }
    stack<LL> nums;
    LL n = 0, count = 0;
    bool toExp = false;
    for (auto &c: s) {
        if (c != '*') {
            n = 10LL * n + (c - '0');
            if (count) {
                if (count > 1) {
                    toExp = true;
                }
                count = 0;
            }
        }
        else {
            count++;
            if (toExp) {
                nums.top() = fpm(nums.top() % mod, n);
                n = 0;
                toExp = false;
                continue;
            }
            if (count == 1) {
                nums.push(n % mod);
                n = 0;
            }
        }
    }
    LL out = 1;
    if (toExp) {
        nums.top() = fpm(nums.top() % mod, n);
        n = 0;
        toExp = false;
    }
    else {
        out = n % mod;
        n = 0;
    }
    while (nums.size()) {
        out = mm(out, nums.top());
        nums.pop();
    }
    cout << out << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
