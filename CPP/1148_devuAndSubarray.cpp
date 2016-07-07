#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
const int maxn = 2e5 + 5;

LL C[maxn], pre[maxn], T[maxn];

void transform()
{
        set<LL> S;
        for (int i = 0; i <= N; i++)
                S.insert(pre[i]);
        int cnt = 1;
        map<LL, LL> mp;
        for (auto &s: S)
                mp[s] = cnt++;
        for (int i = 0; i <= N; i++)
                pre[i] = mp[pre[i]];
}

void show()
{
        for (int i = 0; i <= N; i++)
                printf("%d, %lld, %lld\n", i, C[i], pre[i]);
}

void update(LL idx)
{
        while (idx < maxn)
        {
                T[idx]++;
                idx += (idx&(-idx));
        }
}

LL query(LL idx)
{
        LL ret = 0;
        while (idx)
        {
                ret += T[idx];
                idx -= (idx&(-idx));
        }
        return ret;
}

int main()
{
        memset(pre, 0, sizeof(pre));
        memset(T, 0, sizeof(T));
        C[0] = 0;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
                scanf("%lld", &C[i]);
        for (int i = 1; i <= N; i++)
        {
                LL val;
                scanf("%lld", &val);
                C[i] -= val;
        }
        for (int i = 1; i <= N; i++)
                pre[i] = pre[i - 1] + C[i];
        transform();
        LL ans = 0;
        update(pre[0]);
        for (int i = 1; i <= N; i++)
        {
                ans += query(pre[i]);
                update(pre[i]);
        }
        printf("%lld\n", ans);
        return 0;
}
