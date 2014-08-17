// Segment Trees

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cassert>
#include <utility>
#include <bits/stdc++.h>
#include <stack>
#include <cstdlib>
#include <set>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

vector<vector<LL> > init(vector<LL>& h)
{
	vector<vector<LL> > tree(5100, vector<LL> (15, 1e15));
	int i, j;
	for (i = 0; i < h.size(); i++)
		tree[i][0] = h[i];
	int N = h.size();
	int n = (int) ceil (log2(N));
	for (j = 1; j <= n; j++)
		for (i = 0; i < N; i++)
			tree[i][j] = min(tree[i][j - 1], tree[i + (1 << (j - 1))][j - 1]);
	return tree;
}

int main()
{
	LL n, i, ans = 0;
	cin >> n;
	vector<LL> h(n);
	for (i = 0; i < n; i++)
		cin >> h[i];
	vector<vector<LL> > t = init(h);
	return 0;
}
