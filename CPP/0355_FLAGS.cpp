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

int main()
{
	unsigned long long n, t, p, q, r, s;
	cin >> t;
	while (t--)
	{
		cin >> n;
		p = n * (n - 1);
		q = p * (n - 2);
		r = q * (n - 3);
		cout << 2 * p + 5 * q + 2 * r << endl;
	}
	return 0;
}
