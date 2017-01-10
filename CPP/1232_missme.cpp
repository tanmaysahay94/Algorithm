
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

typedef long long LL;

const LL maxn = 1e7 + 1;
LL sieve[maxn];
const LL maxlen = 1e5 + 5;
char S[maxlen];

void init()
{
    sieve[0] = sieve[1] = 1;
    for (int i = 2; i < maxn; i++)
        if (sieve[i] == 0)
            for (int j = 2 * i; j < maxn; j += i)
                sieve[j] = 1;
}

int main()
{
    init();
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        scanf("%s", S);
        int curr = 0;
        int mx = -1;
        int cnt = 0;
        for (int i = 0; S[i]; i++)
            if (S[i] >= 'a' and S[i] <= 'z')
            {
                if (curr > 0)
                {
                    if (sieve[curr] == 0)
                    {
                        cnt++;
                        mx = max(mx, curr);
//                        trace(curr, cnt, mx);
                    }
                    curr = 0;
                }
            }
            else
                curr = 10 * curr + (S[i] - '0');
        if (curr > 0)
        {
            if (sieve[curr] == 0)
            {
                cnt++;
                mx = max(mx, curr);
//                trace(curr, cnt, mx);
            }
            curr = 0;
        }
        printf("%d %d\n", cnt, mx);
    }
    return 0;
}
