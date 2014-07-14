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

#define num first
#define exp second

typedef long long LL;

inline LL read()
{
	LL n = 0;
	char c;
	while ((c = getchar_unlocked()) < '0');
	n += c-'0';
	while ((c = getchar_unlocked()) >= '0')
		n = (n << 3) + (n << 1) + (c - '0');
	return n;
}

vector<pair<LL, LL> > factorize(LL n, vector<LL>& primeList)
{
	LL i;
	vector<pair<LL, LL> > ans(primeList.size());
	for (i = 0; i < primeList.size(); i++)
	{
		ans[i].num = primeList[i];
		ans[i].exp = 0;
	}
	LL curr = 0;
	while (n != 1 and curr < primeList.size())
	{
		LL count = 0;
		while (n % primeList[curr] == 0 and n != 1)
		{
			n /= primeList[curr];
			count++;
		}
		ans[curr].exp = count;
		curr++;
	}
	return ans;
}

LL powMod(LL base, LL power, LL modulus)
{
	LL ans = 1;
	while (power)
	{
		if (power & 1) ans = (ans * base) % modulus;
		base = (base * base) % modulus;
		power >>= 1;
	}
	return ans;
}

LL multMod(LL a, LL b, LL mod)
{
	return ((a % mod) * (b % mod)) % mod;
}

int main()
{
	LL t, n, i, j, mod = 1e9 + 7;
	vector<bool> prime(10000, true);
	vector<LL> primeList;
	prime[0] = prime[1] = false;
	i = 2;
	while (i < 10000)
	{
		if (prime[i])
			for (int j = i + i; j < 10000; j += i)
				prime[j] = false;
		i++;
	}
	for (i = 0; i < 10000; i++)
		if (prime[i])
			primeList.push_back(i);
	t = read();
	while (t--)
	{
		LL loc;
		n = read();
		vector<LL> v;
		vector<LL> partition;
		vector<bool> visited(n, false);
		for (i = 0; i < n; i++)
		{
			loc = read();
			v.push_back(loc - 1);
		}
		for (LL start = 0; start < n; start++)
			if (not visited[start])
			{
				visited[start] = true;
				LL count = 1;
				for (LL next = v[start]; next != start; next = v[next])
				{
					visited[next] = true;
					count++;
				}
				partition.push_back(count);
			}
		vector<pair<LL, LL> > ans = factorize(partition[0], primeList);
		for (i = 1; i < partition.size(); i++)
		{
			vector<pair<LL, LL> > temp = factorize(partition[i], primeList);
			for (j = 0; j < primeList.size(); j++)
				ans[j].exp = max(ans[j].exp, temp[j].exp);
		}
		LL output = 1;
		for (i = 0; i < primeList.size(); i++)
			output = multMod(output, powMod(ans[i].num, ans[i].exp, mod), mod);
		printf("%lld\n", output % mod);
	}
	return 0;
}
