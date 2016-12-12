
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

inline int f(int a, int b)
{
    return b - a + 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n < 3)
    {
        printf("%d\n", n);
        return 0;
    }
    vector<int> a(n);
    for (auto &b: a)
        scanf("%d", &b);
    vector<int> l(n), r(n);
    l[0] = 0, r[n - 1] = n - 1;
    for (int i = 1, j = n - 2; i < n; i++, j--)
    {
        if (a[i] > a[i - 1]) l[i] = l[i - 1];
        else l[i] = i;
        if (a[j] < a[j + 1]) r[j] = r[j + 1];
        else r[j] = j;
    }
//    for (int i = 0; i < n; i++) trace(i, a[i], l[i], r[i]);
    int ans = 1;
    for (int i = 1; i + 1 < n; i++)
        if (a[i - 1] + 1 < a[i + 1])
            ans = max(ans, 1 + f(l[i - 1], i - 1) + f(i + 1, r[i + 1]));
        else
            ans = max(ans, 1 + max(f(l[i - 1], i - 1), f(i + 1, r[i + 1])));
    ans = max(ans, 1 + f(1, r[1]));
    ans = max(ans, 1 + f(l[n - 2], n - 2));
    printf("%d\n", ans);
    return 0;
}
