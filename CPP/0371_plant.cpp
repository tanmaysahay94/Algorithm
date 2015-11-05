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

unsigned long long mod = 1e9 + 7;

unsigned long long powMod(unsigned long long base, unsigned long long power, unsigned long long modulus)
{
	unsigned long long ans = 1;
	while (power)
	{
		if (power & 1) ans = (ans * base) % modulus;
		base = (base * base) % modulus;
		power >>= 1;
	}
	return ans;
}

unsigned long long sum(unsigned long long val, unsigned long long modulus)
{
	return (val * (val + 1) >> 1) % modulus;
}

int main()
{
	unsigned long long n;
	cin >> n;
	cout << sum(powMod(2, n, mod), mod) << endl;
}
