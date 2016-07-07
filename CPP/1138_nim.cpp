#include <bits/stdc++.h>

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

const LL maxn = 1e4;

vector<int> sieve(maxn, 1);
vector<int> cnt(maxn, 0);
vector<int> win(maxn);

void init()
{
    cnt[1] = 1;
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i < maxn; i++)
        if (sieve[i])
        {
            for (int j = i; j < maxn; j += i)
                sieve[j] = 0, cnt[j]++;
            sieve[i] = 1;
        }
}

void gen()
{
    for (int i = 1; i < maxn; i++)
    {
        if (cnt[i] == 1)
        {
            win[i] = 1;
            continue;
        }
        int state = 0;
        for (int v1 = 1, v2 = i - 1; v1 <= v2 and not state; v1++, v2--)
            if (win[v1] + win[v2] == 1)
                state = 1;
        win[i] = state;
    }
}

int main()
{
    init();
    gen();
    for (int i = 1; i < 100; i++)
        trace(i, sieve[i], win[i]);
    return 0;
}
