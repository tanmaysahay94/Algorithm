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
#define pn puts("")
int main()
{
	vector<vector<int> > v(3, vector<int> (5));
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
			v[i][j] = i + j;
	for (i = 0; i < 3 and printf("\n"); i++)
		for (j = 0; j < 5 and printf(" "); j++)
			cout << v[i][j];
	return 0;
}
