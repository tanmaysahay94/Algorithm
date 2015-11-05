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
	if (k > (n - 1)/2)
		cout << "-1\n";
	else
	{
		cout << n * k << endl;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= k; j++)
				printf("%d %d\n", i, (i + j) % n ? (i + j) % n : n);
	}
	return 0;
}
