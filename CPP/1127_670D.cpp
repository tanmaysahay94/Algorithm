#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, k;
vector<LL> one, have;

bool possible(LL amt, LL magic)
{
    for (int i = 0; i < n; i++)
    {
        if (amt * one[i] > have[i])
            magic -= amt * one[i] - have[i];
        if (magic < 0)
            return 0;
    }
    return magic >= 0;
}

int main()
{
    scanf("%lld%lld", &n, &k);
    one = have = vector<LL> (n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &one[i]);
    for (int i = 0; i < n; i++)
        scanf("%lld", &have[i]);
    LL low = 0, high = 1e15;
    while (high - low > 1)
    {
        int mid = (high + low) / 2;
        if (possible(mid, k))
            low = mid;
        else
            high = mid;
    }
    printf("%lld\n", low);
    return 0;
}
