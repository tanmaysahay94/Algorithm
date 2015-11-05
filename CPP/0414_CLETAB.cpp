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

int get_idx(VI v, int val)
{
	int i;
	for (i = 0; i < v.size(); i++)
		if (v[i] == val)
			return i;
	return -1;						// -1 indicates not found
}

void show(vector<int> v)
{
	int i;
	for (i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int main()
{
	int t, n, m, c, i, j;
	SI(t);
	while (t--)
	{
		SI(n); SI(m);
		int count = 0;
		VI orders_left(405, 0), table(n, 0), order(m);
		for (i = 0; i < m; i++)
		{
			SI(order[i]);
			orders_left[order[i]]++;
		}
		for (i = 0; i < m; i++)
		{
			int curr = order[i];
			orders_left[curr]--;
			int idx = get_idx(table, curr);
			if (idx == -1)			// if the customer doesn't already have a table
			{
				bool placed = false;
				count++;
				for (j = 0; j < n; j++)
					if (table[j] == 0)
					{
						table[j] = curr;
						placed = true;
						break;
					}
				if (not placed)
				{
					for (j = 0; j < n; j++)
						if (orders_left[table[j]] == 0)
						{
							table[j] = curr;
							placed = true;
							break;
						}
				}
				if (not placed)
				{
					int to_update, no_updated = 0;
					vector<bool> found(n, false);
					for (j = i + 1; j < m; j++)
					{
						int index = get_idx(table, order[j]);
						if (index != -1 and not found[index])
						{
							to_update = index;
							found[index] = true;
							no_updated++;
							if (no_updated == n)
								break;
						}
					}
					table[to_update] = curr;
				}
			}
			//			show(table);
		}
		printf("%d\n", count);
	}
	return 0;
}
