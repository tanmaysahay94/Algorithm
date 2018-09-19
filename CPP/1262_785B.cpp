
#include "bits/stdc++.h"
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

long long f(long long high, long long low) {
    return max(0ll, high - low);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long start[2], end[2];
    for (int i = 0; i < 2; i++) {
        end[i] = 1e15;
        start[i] = 0;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long l, h;
        cin >> l >> h;
        end[0] = min(end[0], h);
        start[0] = max(start[0], l);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        long long l, h;
        cin >> l >> h;
        end[1] = min(end[1], h);
        start[1] = max(start[1], l);
    }
    cout << max(
            f(start[0], end[1]),
            f(start[1], end[0])
            );
    return 0;
}
