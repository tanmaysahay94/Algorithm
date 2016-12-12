
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
const LL maxai = 1e6 + 6;

int n, t, s;
vector<LL> A, ans;
LL fr[maxai];
vector<pair<pair<int, int>, int> > Q;

bool cmp(pair<pair<int, int>, int>& l, pair<pair<int, int>, int>& r)
{
    int l_block = l.first.first / s;
    int r_block = r.first.first / s;
    if (l_block != r_block) return l_block < r_block;
    return l.first.second > r.first.second;
}

inline bool inLim(int idx, int s = 0, int e = n)
{
    return s <= idx and idx < e;
}

int main()
{
    scanf("%d%d", &n, &t);
    s = sqrt(n);
    A = vector<LL> (n);
    Q = vector<pair<pair<int, int>, int> > (t);
    ans = vector<LL> (t);
    for (auto &a: A) scanf("%lld", &a);
    int timer = 0;
    for (auto &q: Q)
    {
        scanf("%d%d", &q.first.first, &q.first.second);
        q.second = timer++;
        q.first.first--, q.first.second--;
    }
    sort(Q.begin(), Q.end(), cmp);
    for (auto &q: Q) trace(q.second, q.first.first, q.first.second);
    LL val = 0;
    for (int i = Q[0].first.first; i <= Q[0].first.second; i++)
    {
        val += A[i] * ((fr[A[i]] << 1) | 1ll); 
        fr[A[i]]++;
    }
    ans[Q[0].second] = val;
    for (int i = 1; i < t; i++)
    {
        trace(i);
        int l_start = Q[i - 1].first.first;
        while (l_start < Q[i].first.first and inLim(l_start))
        {
            val -= A[l_start] * ((fr[A[l_start]] << 1) - 1ll);
            fr[A[l_start]]--;
            l_start++;
        }
        l_start--;
        while (l_start >= Q[i].first.first and inLim(l_start))
        {
            val += A[l_start] * ((fr[A[l_start]] << 1) | 1ll);
            fr[A[l_start]]++;
            l_start--;
        }
        int r_start = Q[i - 1].first.second;
        r_start++;
        while (r_start <= Q[i].first.second and inLim(r_start))
        {
            val += A[r_start] * ((fr[A[r_start]] << 1) | 1ll);
            fr[A[r_start]]++;
            r_start++;
        }
        while (r_start > Q[i].first.second + 1 and inLim(r_start))
        {
            val -= A[r_start] * ((fr[A[r_start]] << 1) - 1ll);
            fr[A[r_start]]--;
            r_start--;
        }
        ans[Q[i].second] = val;
    }
    for (auto &a: ans) printf("%lld\n", a);
    return 0;
}
