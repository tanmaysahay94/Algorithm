#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 1e6 + 5;
const LL mod = 1e9 + 7;

LL F[maxn];

int main()
{
        F[0] = 1;
        for (LL i = 1; i < maxn; i++)
                F[i] = (F[i - 1] * i) % mod;
        int t;
        scanf("%d", &t);
        while (t--)
        {
                int n;
                scanf("%d", &n);
                printf("%lld\n", F[n]);
        }
        return 0;
}
