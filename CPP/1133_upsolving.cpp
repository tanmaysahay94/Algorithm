#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL N, M;
vector<LL> q;

bool f(LL t)
{
    LL days = 1;
    LL curr = 0;
    for (int i = 0; i < N; i++)
    {
        if (q[i] > t) return false;
        if (q[i] + curr <= t) curr += q[i];
        else
        {
            days++;
            curr = q[i];
            if (days > M) return false;
        }
    }
    return days <= M;
}

int main()
{
    scanf("%lld%lld", &N, &M);
    q = vector<LL> (N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &q[i]);
    LL low = 0, high = 1e17;
    while (high - low > 1)
    {
        LL mid = (low + high) / 2;
        if (f(mid)) high = mid;
        else low = mid;
    }
    printf("%lld\n", high);
    return 0;
}
