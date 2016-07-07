#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 5;

vector<int> G[maxn];
int in[maxn], done[maxn];
bitset<maxn> f[maxn];

int ans = 0;
int n, m;

void dfs(int v)
{
    if (done[v])
        return;
    for (auto &u: G[v])
        dfs(u);
    f[v][v] = 1;
    for (auto &u: G[v])
        f[v] |= f[u];
    done[v] = 1;
    ans += (2 * f[v].count() >= n);
}

int main()
{
    memset(f, 0, sizeof(f));
    memset(done, 0, sizeof(done));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        in[v]++;
        G[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            dfs(i);
    printf("%d\n", ans);
    return 0;
}
