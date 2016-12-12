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
string S;
LL m;

int f()
{
    int n = S.size();
    S += S;
    vector<int> table(S.size() + 1);
    table[0] = table[1] = 0;
    for (int i = 2; i < (int) table.size(); i++)
    {
        int j = table[i - 1];
        for (;;)
        {
            if (S[j] == S[i - 1])
            {
                table[i] = j + 1;
                break;
            }
            if (j == 0)
            {
                table[i] = 0;
                break;
            }
            j = table[j];
        }
    }
    int ret = n;
    for (int i = 0; i < (int) table.size(); i++)
        if (table[i] >= n)
        {
            ret = i - n;
            break;
        }
    return ret;
}

int main() 
{
    cin >> S;
    scanf("%lld", &m);
    trace(f());
    printf("%lld\n", m / f());
    return 0;
}
