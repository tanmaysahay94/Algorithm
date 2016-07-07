#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 5;

char S[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d%s", &n, S);
        n <<= 1;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (S[i] == 'G') c1++;
                else c2++;
            }
            else
            {
                if (S[i] == 'B') c1++;
                else c2++;
            }
        }
        printf("%d\n", min(c1 / 2, c2 / 2));
    }
    return 0;
}
