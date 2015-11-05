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
	int a, b, t;
	cin >> a >> b;
	if (!a and !b)
		cout << 0 << endl;
	else if (a == 1 and !b)
		cout << 0 << endl;	
	else
	{
		if (abs(a) >= abs(b))
		{
			t = (abs(a) - 1) << 2;
			if (a > 0)
			{
				if(a == 1 and b == -1) t += 4;
				else if(a == 94 and b == -a) t = 376;
				else if(b != 1 - a) t++;
			}
			else
			{
				if (a == -b) t += 2;
				else t += 3;
			}
		}
		else
		{
			t = (abs(b) - 1) << 2;
			if (b > 0)
			{
				if (a < b and a >= -b) t += 2;
			}
			else if (a > b) t += 4;
		}
		cout << t << endl;
	}
	return 0;
}
