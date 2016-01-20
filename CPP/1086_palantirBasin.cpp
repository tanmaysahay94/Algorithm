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

const int maxs = 5e3;
const int inf = INT_MAX;
int S;

inline int genIdx(int i, int j)
{
	return S * i + j;
}

class DSU
{
	vector<int> sz, parent;
	public:
	DSU(int n)
	{
		sz.resize(n);
		parent.resize(n);
		for (int i = 0; i < n; i++)
			sz[i] = 1, parent[i] = i;
	}
	int getSize(int i)
	{
		return sz[i];
	}
	int getAnc(int i)
	{
		if (parent[i] != i)
			parent[i] = getAnc(parent[i]);
		return parent[i];
	}
	void join(int i, int j)
	{
		i = getAnc(i);
		j = getAnc(j);
		if (i == j) return;
		if (getSize(i) < getSize(j))
			swap(i, j);
		parent[j] = i;
		sz[i] += sz[j];
		sz[j] = 0;
	}
};

vector<vector<int> > M(maxs, vector<int> (maxs));
vector<int> ans;

int main()
{
	cin >> S;
	DSU D(S * S);
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			cin >> M[i][j];
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
		{
			int idx = genIdx(i, j);
			int best = inf;
			int bestIdx;
			if (j + 1 < S and best > M[i][j + 1])
				best = M[i][j + 1], bestIdx = genIdx(i, j + 1);
			if (j and best > M[i][j - 1])
				best = M[i][j - 1], bestIdx = genIdx(i, j - 1);
			if (i + 1 < S and best > M[i + 1][j])
				best = M[i + 1][j], bestIdx = genIdx(i + 1, j);
			if (i and best > M[i - 1][j])
				best = M[i - 1][j], bestIdx = genIdx(i - 1, j);
			if (best < M[i][j])
				D.join(idx, bestIdx);
		}
	for (int i = 0; i < S * S; i++)
	{
		int sz = D.getSize(i);
		if (sz)
			ans.push_back(sz);
	}
	sort(ans.rbegin(), ans.rend());
	for (auto &a: ans) cout << a << ' ';
	cout << endl;
	return 0;
}
