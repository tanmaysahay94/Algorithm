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

unsigned long long ans = 1e18;

void oba(unsigned long long val, unsigned long long used)
{
	if (used >= ans)
		return;
	if (!val)
	{
		ans = used;
		return;
	}
	unsigned long long no = 0, ones = 0;
	while (no * 10 + 1 <= val)
		no = no * 10 + 1, ones++;
	oba(val % no, used + val/no * ones);
	oba(no * 10 + 1 - val, used + ones + 1);
}
int main()
{
	unsigned long long n;
	cin >> n;
	oba(n, 0);
	cout << ans << endl;
}
