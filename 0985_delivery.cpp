#include <bits/stdc++.h>

using namespace std;

const int maxk = 1e5 + 5;
const int maxn = 1e5 + 5;

int n, m, k;
set<int> toVisit;
vector<int> G[maxn], GR[maxn], edgeFrom[maxn], edgeFromComponent[maxn];
vector<int> vis(maxn), inComponent(maxn), edgeCountHelper(maxn);
stack<int> S;
vector<pair<int, int> > edges, cIDordering;
vector<vector<int> > components;

void dfs1(int v)
{
	if (vis[v])
		return;
	vis[v] = 1;
	for (auto u: G[v])
		dfs1(u);
	S.push(v);
}

void dfs2(int v, vector<int>& c, int cid)
{
	if (vis[v])
		return;
	vis[v] = 1;
	c.push_back(v);
	inComponent[v] = cid;
	for (auto e: edgeFrom[v])
		edgeFromComponent[cid].push_back(e);
	for (auto u: GR[v])
		dfs2(u, c, cid);
}

void init()
{
	for (int i = 0; i < maxn; i++)
		G[i].clear(), GR[i].clear(), edgeFrom[i].clear(), edgeFromComponent[i].clear(), vis[i] = 0, inComponent[i] = -1, edgeCountHelper[i] = 0;
	components.clear();
	cIDordering.clear();
	toVisit.clear();
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		init();
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < k; i++)
		{
			int city;
			scanf("%d", &city);
			toVisit.insert(city);
		}
		for (int i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (x == y)
				continue;
			edges.push_back(make_pair(x, y));
			G[x].push_back(y);
			GR[y].push_back(x);
			edgeFrom[x].push_back(i);
		}
		for (int i = 1; i <= n; i++)
			if (not vis[i])
				dfs1(i);
		vis.clear(); vis.resize(maxn);
		int componentID = 0;
		while (not S.empty())
		{
			vector<int> component;
			int v = S.top();
			S.pop();
			if (vis[v])
				continue;
			dfs2(v, component, componentID);
			componentID++;
			sort(component.begin(), component.end());
			components.push_back(component);
		}
		cIDordering.resize(0); cIDordering.resize(componentID);
		for (int i = 0; i < componentID; i++)
			cIDordering[i].first = 0, cIDordering[i].second = i;
		for (int i = 0; i < (int) edges.size(); i++)
		{
			int u = edges[i].first, v = edges[i].second;
			if (inComponent[u] != inComponent[v])
				cIDordering[inComponent[v]].first++, edgeCountHelper[inComponent[v]]++;
		}
		multiset<pair<int, int> > ms;
		for (int i = 0; i < componentID; i++)
			ms.insert(cIDordering[i]);
		vector<int> topo;
		while (not ms.empty())
		{
			pair<int, int> foo = *(ms.begin());
			ms.erase(ms.begin());
			int cno = foo.second;
			topo.push_back(cno);
			map<int, int> thingsToChange;
			for (auto eno: edgeFromComponent[cno])
			{
				int to = edges[eno].second;
				int toComp = inComponent[to];
				if (toComp != cno)
					thingsToChange[toComp]--;
			}
			for (auto bar: thingsToChange)
			{
				int cnoChanged = bar.first;
				int diff = bar.second;
				multiset<pair<int, int> >::iterator help = ms.find(make_pair(edgeCountHelper[cnoChanged], cnoChanged));
				pair<int, int> pertinent = *help;
				ms.erase(help);
				pertinent.first = max(0, pertinent.first + diff);
				edgeCountHelper[cnoChanged] = pertinent.first;
				ms.insert(pertinent);
			}
		}
		vector<int> ans;
		for (int i = 0; i < (int) topo.size(); i++)
		{
			int cno = topo[i];
			for (int j = 0; j < (int) components[cno].size(); j++)
				if (toVisit.count(components[cno][j]))
					ans.push_back(components[cno][j]);
		}
		for (auto A: ans)
			printf("%d ", A);
		puts("");
	}
	return 0;
}
