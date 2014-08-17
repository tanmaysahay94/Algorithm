// Segment Tree or seg tree for min operation

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
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

const int MAX_INF = 1e9;

vector<vector<int> > init(vector<int>& v)
{
	int N = v.size();
	int n = (int) ceil(log2(N));
	vector<vector<int> > segTree (N, vector<int> (n + 1, MAX_INF));
	int i, j;
	for (i = 0; i < N; i++)
		segTree[i][0] = v[i];
	for (j = 1; j <= n; j++)
		for (i = 0; i < N; i += (1 << j))
			segTree[i][j] = min(segTree[i][j - 1], segTree[i + (1 << (j - 1))][j - 1]);
	return segTree;
}

void update(vector<int>& v, vector<vector<int> >& segTree, int idx, int val)
{
	int j;
	int n = segTree[0].size();
	v[idx] = segTree[idx][0] = val;
	for (j = 1; j <= n; j++)
	{
		int i = idx - (idx & ((1 << j) - 1));
		segTree[i][j] = min(segTree[i][j - 1], segTree[i + (1 << (j - 1))][j - 1]);
	}
}

void show(vector<vector<int> >& segTree, int left, int right)
{
	int result = MAX_INF;
}

int main()
{
	int n, i, proceed, choice, x, y;
	cin >> n;
	vector<int> v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];
	vector<vector<int> > tree = init(v);
	do
	{
		cout << "1. Update\n2. Show\n";
		cin >> choice;
		if (choice == 1)
		{
			cin >> x >> y;
			update(v, tree, x, y);
		}
		else
		{
			cin >> x >> y;
			show(tree, x, y);
		}
		cout << "Want to proceed? (1/0)\n";
		cin >> proceed;
	} while (proceed);
	return 0;
}
