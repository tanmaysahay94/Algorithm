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

#define con first
#define bas second

typedef long long LL;

LL gcd(LL a, LL b)
{
	LL r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

LL lcm(LL a, LL b)
{
	return (a / gcd(a, b)) * b;
}
/*
LL fast_pow(LL base, LL n, LL m)
{
	if (not n)
		return 1;
	if (n == 1)
		return base;
	LL halfn = fast_pow(base, n/2, m);
	if (n & 1)
		return (((halfn * halfn) % m) * base) % m;
	else
		return (halfn * halfn) % m;
}

LL getInverse(LL val, LL base)
{
	return fast_pow(base, val - 2, val);
}
*/

LL getInverse(LL val, LL base)
{
	LL curr, prev = val;
	for (LL i = 0; i < base; i++)
	{
		curr = prev;
		curr = (curr * val) % base;
		if (curr == 1) break;
		else prev = curr;
	}
	return prev;
}

pair<LL, LL> chineseRemainderTheorem(vector<pair<LL, LL> >& mod_map)
{
	LL ans = 0, workingProd, totalProd = mod_map[0].bas, totalGCD = mod_map[0].bas, totalLCM = mod_map[0].bas;
	for (LL i = 1; i < mod_map.size(); i++)
	{
		totalProd = totalProd * mod_map[i].bas;
		totalGCD = gcd(totalGCD, mod_map[i].bas);
		totalLCM = lcm(totalLCM, mod_map[i].bas);
	}
	bool solvable = true;
	for (LL i = 1; i < mod_map.size(); i++)
		if (mod_map[i].con % totalGCD != mod_map[i - 1].con % totalGCD)
		{
			solvable = false;
			break;
		}
	if (not solvable)
		return make_pair(0 , 0);
	for (LL i = 0; i < mod_map.size(); i++)
	{
		workingProd = totalProd / mod_map[i].bas;
		ans = (ans + mod_map[i].con * workingProd * getInverse(workingProd % mod_map[i].bas, mod_map[i].bas)) % totalLCM;
	}
	return make_pair(ans, totalLCM);
}

int main()
{
	LL n, i, congruence, base;
	vector<pair<LL, LL> > mod_map;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> congruence >> base;
		mod_map.push_back(make_pair(congruence % base, base));
	}
	pair<LL, LL> ans;
	ans = chineseRemainderTheorem(mod_map);
	printf("%lld (mod %lld)\n", ans.con, ans.bas);
}
