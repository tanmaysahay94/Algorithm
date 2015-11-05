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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	if (n == 3)
	{
		if (v[1] - v[0] == v[2] - v[1])
			cout << 2 * v[2] - v[1];
		else if (v[1] - v[0] < v[2] - v[1])
			cout << 2 * v[1] - v[0];
		else
			cout << v[0] + v[2] - v[1];
	}
	else
	{
		bool found = false;
		int diff;
		for (int i = 2; i < n and not found; i++)
			if (v[i] - v[i - 1] == v[i - 1] - v[i - 2])
			{
				diff = v[i] - v[i - 1];
				found = true;
			}
		bool printed = false;
		for (int i = 1; i < n and not printed; i++)
			if (v[i] - v[i - 1] != diff)
			{
				cout << v[i - 1] + diff;
				printed = true;
			}
		if (not printed)
			cout << v[n - 1] + diff;
	}
	return 0;
}
