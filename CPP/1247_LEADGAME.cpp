#include "bits/stdc++.h"
using namespace std;
int main()
{
    int winner = -1, margin = -1;
    int __T;
    int sa = 0, sb = 0;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        sa += a;
        sb += b;
        int diff = abs(sa - sb);
        if (diff > margin)
        {
            margin = diff;
            winner = 1 + (sb > sa);
        }
    }
    printf("%d %d\n", winner, margin);
    return 0;
}
