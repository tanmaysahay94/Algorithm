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

typedef unsigned long long ULL;

pair<vector<bool>, vector<ULL> > prime_generator(ULL n)
{
	ULL use = n + 1;
	vector<bool> prime(use, true);
	vector<ULL> primeList;
	prime[0] = prime[1] = false;
	ULL i = 2;
	while (i < use)
	{
		if (prime[i])
			for (int j = i + i; j < use; j += i)
				prime[j] = false;
		i++;
	}
	for (i = 0; i < use; i++)
		if (prime[i])
			primeList.push_back(i);
	return make_pair(prime, primeList);
}

int main()
{
	int n;
	cin >> n;
	pair<vector<bool>, vector<ULL> > prime_package = prime_generator(n);
	vector<bool> prime = prime_package.first;
	vector<ULL> primeList = prime_package.second;
	return 0;
}
