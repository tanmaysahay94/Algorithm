#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	int n;
	cin >> n;
	int c0(0), c5(0);
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		if (val == 5)
			c5++;
		else
			c0++;
	}
	if (c0 == 0)
		cout << -1;
	else if (c5 < 9)
		cout << 0;
	else
	{
		for (int i = 0; i < c5/9; i++)
			for (int j = 0; j < 9; j++)
				cout << 5;
		for (int i = 0; i < c0; i++)
			cout << 0;
	}
	return 0;
}
