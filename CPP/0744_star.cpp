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
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a] = v[b] = 1;
	}
	int city;
	for (int i = 0; i < n; i++)
		if (not v[i])
		{
			city = i + 1;
			break;
		}
	cout << n - 1 << endl;
	for (int i = 1; i <= n; i++)
		if (i != city)
			printf("%d %d\n", i, city);
	return 0;
}
