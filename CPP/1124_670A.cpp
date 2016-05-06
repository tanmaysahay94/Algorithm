#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int mn = 0, mx = 0;
    for (int i = 0; i < n; i++)
        if (i % 7 > 4) mn++;
        else if (i % 7 < 2) mx++;
    printf("%d %d\n", mn, mx);
    return 0;
}
