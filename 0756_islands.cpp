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
	int n, k;
	cin >> n >> k;
	int p = n * n;
	if (k > p/2 + (p&1))
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		vector<vector<char> > v(n, vector<char> (n, 'S'));
		if (n & 1)
			for (int i = 0, idx = 0; i < k and idx < p; i++, idx += 2)
				v[idx/n][idx%n] = 'L';
		else
		{
			int cnt = 0;
			for (int i = 0; i < n and cnt < k; i+=2)
				for (int j = 0; j < n and cnt < k; j+=2)
					v[i][j] = 'L', cnt++;
			for (int i = 1; i < n and cnt < k; i+=2)
				for (int j = 1; j < n and cnt < k; j+=2)
					v[i][j] = 'L', cnt++;
		}
		for (int i = 0; i < n; i++, cout << endl)
			for (int j = 0; j < n; j++)
				cout << v[i][j];
	}
	return 0;
}
