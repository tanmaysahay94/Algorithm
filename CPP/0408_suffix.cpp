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

bool subStringSearch(string large, string small)
{
	int l = large.length();
	int s = small.length();
	int i = 0, j = 0;
	while (j < l)
	{
		if (small[i] == large[j])
			i++;
		j++;
		if (i == s)
			break;
	}
	return i == s;
}

int main()
{
	int i, j;
	string s, t;
	cin >> s >> t;
	vector<int> a(26, 0), b(26, 0);
	for (i = 0; s[i]; i++)
		a[s[i] - 'a']++;
	for (i = 0; t[i]; i++)
		b[t[i] - 'a']++;
	for (i = 0; i < 26; i++)
		if (b[i] > a[i])
		{
			cout << "need tree\n";
			return 0;
		}
	if (s.length() == t.length())
	{
		cout << "array\n";
		return 0;
	}
	bool found = subStringSearch(s, t);
	if (found) cout << "automaton\n";
	else cout << "both\n";
	return 0;
}
