#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 1e5 + 5;

LL A[maxn], MEH[maxn][2];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        A[0] = MEH[0][0] = MEH[0][1] = 0;
        LL ans = LLONG_MIN;
        bool allNeg = true;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &A[i]);
            if (A[i] > 0) allNeg = false;
            MEH[i][0] = max(A[i], A[i] + MEH[i - 1][0]);
            ans = max(ans, MEH[i][0]);
        }
        if (allNeg)
        {
            printf("%lld\n", ans);
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            MEH[i][1] = max(MEH[i - 1][0], A[i] + MEH[i - 1][1]);
            ans = max(ans, MEH[i][1]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
