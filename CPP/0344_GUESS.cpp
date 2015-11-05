#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
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

unsigned long long euclid(unsigned long long p, unsigned long long q)
{
	unsigned long long r;
	if (p < q) swap(p, q);
	while (q != 0)
	{
		r = p % q;
		p = q;
		q = r;
	}
	return p;
}
int main()
{
	unsigned long long t, n, m, total, possible, oddn, oddm, evenn, evenm, a, b, gcd;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		total = n * m;
		evenn = n >> 1;
		evenm = m >> 1;
		oddn = n - evenn;
		oddm = m - evenm;
		possible = oddm * evenn + oddn * evenm;
		gcd = euclid(possible, total);
		cout << possible/gcd << "/" << total/gcd << endl;
	}
	return 0;
}
