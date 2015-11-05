#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	bool found = false;
	int end = n / 7;
	int c7, c4;
	int num_dig = 1e7;
	int cnt7 = 1e7, cnt4 = -1;
	for (int i = 0; i <= end; i++)
	{
		int a = n - 7 * i;
		if (a % 4 == 0)
		{
			c7 = i;
			c4 = a / 4;
			if (c4 + c7 < num_dig)
			{
				num_dig = c4 + c7;
				cnt4 = c4, cnt7 = c7, found = true;
			}
			else if (c4 + c7 == num_dig and c4 > cnt4)
				cnt4 = c4, cnt7 = c7, found = true;
		}
	}
	if (not found)
		cout << -1;
	else
	{
		c4 = cnt4, c7 = cnt7;
		for (int i = 0; i < c4; i++)
			cout << 4;
		for (int i = 0; i < c7; i++)
			cout << 7;
	}
	return 0;
}
