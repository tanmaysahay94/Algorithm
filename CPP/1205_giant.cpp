
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
    vector<int> M(1e5 + 5);
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        for (int j = val; j < 1e5 + 5; j += val)
            M[j]++;
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int x, k;
        scanf("%d%d", &x, &k);
        printf("%s\n", M[x] >= k ? "Yes" : "No");
    }
    return 0;
}
