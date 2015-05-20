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
	int v[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	int ans[n];
	for (int i = 0; i < n; i++)
		ans[i] = 0;
	for (int i = 0; i < n; i++)
	{
		bool p = true;
		for (int j = 0; j < n and p; j++)
			if (v[i][j] == 1 or v[i][j] == 3)
				p = false;
		if (p)
			ans[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (not ans[i])
			continue;
		bool p = true;
		for (int j = 0; j < n and p; j++)
			if (v[j][i] == 2 or v[j][i] == 3)
				p = false;
		if (not p)
			ans[i] = 0;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += ans[i];
	cout << cnt << endl;
	for (int i = 0; i < n; i++)
		if (ans[i])
			cout << i + 1 << ' ';
	cout << endl;
	return 0;
}
