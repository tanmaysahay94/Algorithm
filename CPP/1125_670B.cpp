#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    LL n, k;
    scanf("%lld%lld", &n, &k);
    LL idx = 1;
    while (idx < n and (idx * (idx + 1)) / 2 < k) idx++;
    k -= (idx * (idx - 1)) / 2;
    int out;
    for (int i = 1; i <= k; i++)
        scanf("%d", &out);
    printf("%d\n", out);
    return 0;
}
