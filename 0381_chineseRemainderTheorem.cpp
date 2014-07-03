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

typedef unsigned long long ULL;

ULL gcd(ULL a, ULL b)
{
	ULL r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

ULL lcm(ULL a, ULL b)
{
	return (a / gcd(a, b)) * b;
}

ULL getInverse(ULL val, ULL base)
{
	ULL curr, prev = val;
	for (ULL i = 0; i < base; i++)
	{
		curr = prev;
		curr = (curr * val) % base;
		if (curr == 1) break;
		else prev = curr;
	}
	return prev;
}

pair<ULL, ULL> chineseRemainderTheorem(vector<pair<ULL, ULL> >& mod_map)
{
	ULL ans = 0, workingProd, totalProd = mod_map[0].bas, totalGCD = mod_map[0].bas, totalLCM = mod_map[0].bas;
	for (ULL i = 1; i < mod_map.size(); i++)
	{
		totalGCD = gcd(totalGCD, mod_map[i].bas);
		totalLCM = lcm(totalLCM, mod_map[i].bas);
		totalProd = totalProd * mod_map[i].bas;
	}
	bool solvable = true;
	for (ULL i = 1; i < mod_map.size(); i++)
		if (mod_map[i].con % totalGCD != mod_map[i - 1].con % totalGCD)
		{
			solvable = false;
			break;
		}
	if (not solvable)
		return make_pair(0 , 0);
	for (ULL i = 0; i < mod_map.size(); i++)
	{
		workingProd = totalProd / mod_map[i].bas;
		ans = (ans + mod_map[i].con * workingProd * getInverse(workingProd, mod_map[i].bas)) % totalLCM;
	}
	return make_pair(ans, totalLCM);
}

int main()
{
	ULL n, i, congruence, base;
	vector<pair<ULL, ULL> > mod_map;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> congruence >> base;
		mod_map.push_back(make_pair(congruence % base, base));
	}
	pair<ULL, ULL> ans;
	ans = chineseRemainderTheorem(mod_map);
	printf("%llu (mod %llu)\n", ans.con, ans.bas);
}
