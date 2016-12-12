
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

vector<vector<LL>> operator *(vector<vector<LL>>& A, vector<vector<LL>>& B)
{
    assert(A.size()); assert(B.size());
    int r1 = A.size(), c1 = A[0].size(), r2 = B.size(), c2 = B[0].size();
    assert(c1 == r2);
    vector<vector<LL>> C(r1, vector<LL> (c2));
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
            {
                C[i][j] += ((A[i][k] % mod) * (B[k][j] % mod));
                C[i][j] %= mod;
            }
    return C;
}

vector<vector<LL>> fastPow(vector<vector<LL>>& V, int p)
{
    int dim = V.size();
    vector<vector<LL>> I(dim, vector<LL> (dim));
    for (int i = 0; i < (int) I.size(); i++)
        I[i][i] = 1;
    while (p)
    {
        if (p & 1)
            I = I * V;
        V = V * V;
        p >>= 1;
    }
    return I;
}

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int N, M;
        scanf("%d%d", &N, &M);
        vector<vector<LL>> T_even(M + 2, vector<LL> (M + 2));
        for (int i = 1; i <= M; i++)
            T_even[i][i - 1] = T_even[i][i + 1] = 1;
        auto T_odd = T_even;
        for (int i = 1; i <= M; i++)
            T_odd[i][i] = 1;
        auto T_combined = T_even * T_odd;
        vector<vector<LL>> base(M + 2, vector<LL> (1));
        for (int i = 1; i <= M; i++)
            base[i][0] = 1;
        auto lval = fastPow(T_combined, (N - 1) / 2);
        auto ans = lval * base;
        if ((N - 1) % 2)
            ans = T_even * ans;
        LL val = 0;
        for (auto &_res: ans)
            for (auto &res: _res)
                val = (val + res) % mod;
        printf("%lld\n", val);
    }
    return 0;
}
