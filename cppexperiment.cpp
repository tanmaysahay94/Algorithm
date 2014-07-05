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
	int i;
	vector<bool> prime(1000, true);
	vector<int> primeList;
	prime[0] = prime[1] = false;
	i = 2;
	while (i < 1000)
	{
		if (prime[i])
			for (int j = i + i; j < 1000; j += i)
				prime[j] = false;
		i++;
	}
	for (i = 0; i < 1000; i++)
		if (prime[i])
			cout << i << " ";
	cout << endl;
	return 0;
}
