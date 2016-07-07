#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5;

int main()
{
        int t;
        scanf("%d", &t);
        while (t--)
        {
                int n;
                scanf("%d", &n);
                bool possible = false;
                int prev = -1, curr, count;
                for (int i = 0; i < n; i++)
                {
                        scanf("%d", &curr);
                        if (curr != prev)
                                prev = curr, count = 1;
                        else
                                count++;
                        if (count >= 3)
                                possible = true;
                }
                if (possible)
                        printf("Yes\n");
                else
                        printf("No\n");
        }
        return 0;
}
