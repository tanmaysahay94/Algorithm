#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    bool hasZero = false;
    scanf("%d%d", &N, &K);
    vector<int> V(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
        if (V[i] == 0)
            hasZero = true;
    }
    vector<int> pre(N + 1);
    map<int, int> mp;
    mp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        pre[i + 1] = pre[i] + V[i];
        mp[pre[i + 1]] = i + 1;
    }
    bool possible = false;
    if (K == 0)
        possible = hasZero;
    else
        for (int i = 0; i <= N and not possible; i++)
            if (mp.count(pre[i] + K))
                possible = true;
    if (possible)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
