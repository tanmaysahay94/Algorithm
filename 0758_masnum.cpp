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
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n == 0)
			cout << 0 << endl;
		else if (n & 1)
			cout << 0 << endl;
		else
		{
			cout << 9;
			for (int i = 1; i < n/2; i++)
				cout << 0;
			cout << endl;
		}
	}
	return 0;
}
