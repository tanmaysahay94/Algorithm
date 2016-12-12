
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

int main()
{
    int n;
    scanf("%d", &n);
    string S;
    cin >> S;
    vector<int> ans;
    int cnt = 0;
    for (auto &s: S)
    {
        if (s == 'B') cnt++;
        else {
            if (cnt) {
                ans.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if (cnt) {
        ans.push_back(cnt);
    }
    printf("%d\n", (int) ans.size());
    for (auto &a: ans) printf("%d ", a);
    return 0;
}
