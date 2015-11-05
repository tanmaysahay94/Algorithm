#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	int i, j, n, v, small = 0, big = 0;
	bool t = false;
	cin >> n;
	if (n > 1)
	{
		for (i = 0; i < n; i++)
		{
			cin >> v;
			if (v == 100)
				small++;
			else
				big++;
		}
		for (i = 0; i <= small; i++)
		{
			for (j = 0; j <= big; j++)
				if (i + 2 * j == small - i + 2 * (big - j))
				{
					t = true;
					break;
				}
			if (t)
				break;
		}
	}
	if (t)
		cout << "YES\n";
	else
		cout << "NO\n";
}
