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

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	string s;
	for (i = 0; i < n; i++)
	{
		cin >> s;
		for (j = 0; s[j]; j++)
		{
			if (s[j] == '-')
				cout << s[j];
			else
			{
				if ((i + j) & 1)
					cout << 'W';
				else
					cout << 'B';
			}
		}
		cout << endl;
	}
	return 0;
}
