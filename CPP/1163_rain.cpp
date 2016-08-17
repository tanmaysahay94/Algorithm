
#include <bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename __Tp1>
void __f(const char* name, __Tp1&& __tp1){
    cerr << name << " : " << __tp1 << std::endl;
}
template <typename __Tp1, typename... __Tps>
void __f(const char* names, __Tp1&& __tp1, __Tps&&... __tps){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " <<  __tp1 << " | " ;
    __f(comma+1, __tps...);
}
#else
#define trace(...)
#endif

const int maxr = 55;
const int maxc = 55;

int H[maxr][maxc], can[maxr][maxc], W[maxr][maxc];
int R, C;

void dfs1(int r, int c)
{
    if (r < 1 or r > R or c < 0 or c > C) return;
    if (not can[r][c]) return;
    can[r][c] = 0;
    int h = H[r][c];
    if (H[r - 1][c] >= h) dfs1(r - 1, c);
    if (H[r + 1][c] >= h) dfs1(r + 1, c);
    if (H[r][c - 1] >= h) dfs1(r, c - 1);
    if (H[r][c + 1] >= h) dfs1(r, c + 1);
}

int e(int a, int b)
{
    return 60 * a + b;
}

void dfs2(int r, int c, int& fillTo, unordered_set<int>& u)
{
//    trace(r, c, H[r][c], fillTo);
    if (r < 0 or r > R or c < 0 or c > C) return;
    if (not can[r][c]) return;
    can[r][c] = -1;
    if (H[r][c] >= fillTo) return;
    u.insert(e(r, c));
    if (not can[r - 1][c] and not u.count(e(r - 1, c))) fillTo = min(fillTo, H[r - 1][c]);
    if (not can[r + 1][c] and not u.count(e(r + 1, c))) fillTo = min(fillTo, H[r + 1][c]);
    if (not can[r][c - 1] and not u.count(e(r, c - 1))) fillTo = min(fillTo, H[r][c - 1]);
    if (not can[r][c + 1] and not u.count(e(r, c + 1))) fillTo = min(fillTo, H[r][c + 1]);
    if (can[r - 1][c] and not u.count(e(r - 1, c))) dfs2(r - 1, c, fillTo, u);
    if (can[r + 1][c] and not u.count(e(r + 1, c))) dfs2(r + 1, c, fillTo, u);
    if (can[r][c - 1] and not u.count(e(r, c - 1))) dfs2(r, c - 1, fillTo, u);
    if (can[r][c + 1] and not u.count(e(r, c + 1))) dfs2(r, c + 1, fillTo, u);
    W[r][c] = fillTo;
    can[r][c] = 0;
}

void show()
{
    for (int i = 0; i < R + 2; i++, printf("\n"))
        for (int j = 0; j < C + 2; j++)
            printf("%d ", can[i][j]);
}

int main()
{
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        scanf("%d%d", &R, &C);
        memset(H, 0, sizeof(H));
        memset(W, 0, sizeof(W));
        memset(can, 0, sizeof(can));
        for (int r = 1; r <= R; r++)
            for (int c = 1; c <= C; c++)
            {
                scanf("%d", &H[r][c]);
                W[r][c] = H[r][c];
                can[r][c] = 1;
            }
//        show();
        for (int c = 1; c < C; c++)
            dfs1(1, c);
        for (int r = 1; r < R; r++)
            dfs1(r, C);
        for (int c = C; c > 1; c--)
            dfs1(R, c);
        for (int r = R; r > 1; r--)
            dfs1(r, 1);
//        printf("--------------------------\n");
//        show();
        for (int r = 1; r <= R; r++)
            for (int c = 1; c <= C; c++)
                if (can[r][c])
                {
                    int fillTo = INT_MAX;
                    unordered_set<int> u;
                    dfs2(r, c, fillTo, u);
                }
        int ans = 0;
        for (int r = 1; r <= R; r++)
            for (int c = 1; c <= C; c++)
                ans += max(W[r][c] - H[r][c], 0);
        printf("Case #%d: %d\n", T, ans);
    }
    return 0;
}
