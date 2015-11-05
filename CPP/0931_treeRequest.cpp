#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5;
int n, m;
vector<int> G[maxn], pre[maxn], Nlvl[maxn], mapTo(maxn), L(maxn), last(maxn);
char S[maxn];
int id;

void input()
{
	id = 0;
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++)
	{
		int parent;
		scanf("%d", &parent);
		G[parent].push_back(i);
	}
	scanf("%s", S);
}

void dfs(int v = 1, int depth = 1)
{
	mapTo[v] = ++id;
	L[v] = depth;
	Nlvl[depth].push_back(id);
	pre[depth].push_back(1 << (S[v - 1] - 'a'));
	for (auto g: G[v])
		dfs(g, depth + 1);
	last[v] = id;
}

void genPre()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < (int) pre[i].size(); j++)
			pre[i][j] ^= pre[i][j - 1];
}

void solve()
{
	int v, h;
	while (m--)
	{
		scanf("%d%d", &v, &h);
		int start = mapTo[v];
		int end = last[v];
		vector<int>::iterator sit = lower_bound(Nlvl[h].begin(), Nlvl[h].end(), start);
		vector<int>::iterator eit = upper_bound(Nlvl[h].begin(), Nlvl[h].end(), end);
		if(sit == eit)
		{
			printf("Yes\n");
			continue;
		}
		eit--;
		int sidx = sit - Nlvl[h].begin();
		int eidx = eit - Nlvl[h].begin();
		int cnt = pre[h][eidx];
		if (sidx)
			cnt ^= pre[h][--sidx];
		if (! (cnt & (cnt - 1)))
			printf("Yes\n");
		else
			printf("No\n");
	}
}

int main()
{
	input();
	dfs();
	genPre();
	solve();
	return 0;
}
