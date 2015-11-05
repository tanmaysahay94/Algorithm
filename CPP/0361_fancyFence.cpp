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
	int t;
	float a, v;
	cin >> t;
	while (t--)
	{
		cin >> a;
		v = 360.0/(180.0 - a);
		if (v > 2 and v == floor(v))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
