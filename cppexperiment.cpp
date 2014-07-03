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
int gcd(int a, int b)
{
	if (not b) return a;
	return gcd(b, a % b);
}
int lcm(int a, int b)
{
	return (a/gcd(a, b)) * b;
}
int main()
{
	int  i, n, totalGCD, totalLCM;
	cin >> n;
	vector<int> v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];
	totalGCD = totalLCM = v[0];
	for (i = 1; i < n; i++)
	{
		totalGCD = gcd(totalGCD, v[i]);
		totalLCM = lcm(totalLCM, v[i]);
	}
	printf("gcd: %d\n", totalGCD);
	printf("lcm: %d\n", totalLCM);
}
