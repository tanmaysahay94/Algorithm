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
	int n, sum = 0;
	cin >> n;
	for (int i = 0, x; i < n; i++)
	{
		cin >> x;
		sum += x;
	}
	if (sum == 2 * (n - 1))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
