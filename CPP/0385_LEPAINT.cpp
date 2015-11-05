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

double mem[105][105] = {0};
double fact[105] = {0};

double factorial(ULL a)
{
	if (not a) return 1;
	if (fact[a]) return fact[a];
	double ans = 1;
	ULL i;
	for (i = 1; i <= a; i++)
		ans = ans * i;
	fact[a] = ans;
	return ans;
}

double choose(ULL a, ULL b)
{
	if (mem[a][b]) return mem[a][b];
	double num, dena, denb;
	if (fact[a]) num = fact[a];
	else num = fact[a] = factorial(a);
	if (fact[b]) dena = fact[b];
	else dena = fact[b] = factorial(b);
	if (fact[a - b]) denb = fact[a - b];
	else denb = fact[a - b] = factorial(a - b);
	mem[a][b] = num/(dena * denb);
	return mem[a][b];
}

int main()
{
	ULL t, n, c, k, l, r, i, j;
	double times[105][55][105] = {0};							// i - colour, j - step, k - no. of times that paint was seen at that level
	for (i = 0; i < 105; i++)
		times[i][0][1] = 1;
	double expectation[105][55] = {0};
	scanf("%llu", &t);
	while (t--)
	{
		scanf("%llu%llu%llu", &n, &c, &k);
		vector<ULL> count(n, 0);
		double sample[105][105] = {0}, sum = 0, ans = 0;
		for (i = 0; i < c; i++)
			for (j = 0; j < c; j++)
				sample[i][(i * j) % c]++;
		for (i = 0; i < k; i++)
		{
			scanf("%llu%llu", &l, &r);
			l--; r--;
			for (j = l; j <=r; j++)
				count[j]++;
		}
		ULL upto = 0;
		for (i = 0; i < n; i++)
			upto = max(upto, count[i]);
		for (i = 1; i <= upto; i++)								// here, 'i' denotes the level
			if (times[c][i][1])
				continue;
			else
				for (j = 1; j <= c; j++)						// here 'j' denotes the colour (in the previous level)
					if (times[c][i - 1][j])
						for (k = 0; k < c; k++)					// here 'k' denotes the colour it's painted with
							times[c][i][k] += times[c][i - 1][j] * sample[j][k];
		for (i = 0; i <= upto; i++)								// here 'i' denotes the level
			if (not expectation[c][i])
			{
				sum = 0;
				for (j = 1; j < c; j++)
					sum += j * times[c][i][j];
				expectation[c][i] = sum/pow(c, i);
			}
		for (i = 0; i < n; i++)									// here 'i' denotes the cell
			for (j = 0; j <= count[i]; j++)
				ans += expectation[c][j] * choose(count[i], j) / ((double) pow(2, count[i]));
		printf("%.9lf\n", ans);
	}
	return 0;
}
