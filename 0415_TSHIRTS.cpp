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

int main()
{
	int t, n, i, j, val;
	SI(t);
	while (t--)
	{
		SI(n);
		VI ts[n];
		vector<vector<bool> > present(n, vector<bool> (100, false));
		char ch;
		int count = 0;
		while (count < n)
		{
			SI(val); val--;
			ts[count].pb(val);
			present[count][val] = true;
			scanf("%c", &ch);
			while (ch == ' ')
			{
				SI(val); val--;
				ts[count].pb(val);
				present[count][val] = true;
				scanf("%c", &ch);
			}
			count++;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < 100; j++)
				cout << present[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
