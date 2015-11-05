#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int arr[20][100005], foo[100005], bar[20];

int main()
{
	long long sum = 0;
	int n, m, y, l, x;
	cin >> n;
	for (int i = 0; i < 20; i++)
		bar[i] = (1 << i);
	for (int i = 0; i < n; i++)
		cin >> arr[0][i];
	for (l = 1, x = 1; x <= n; l++, x <<= 1)
		for (int i = 0; i < n; i++)
			arr[l][i] = max(arr[l - 1][i], ((i + x < n) ? arr[l - 1][i + x] : 0));
	cin >> m;
	cin >> x >> y;
	foo[0] = foo[1] = 0;
	for (int i = 2; i <= n; i++)
		foo[i] = 1 + foo[i >> 1];
	while (m--)
	{
		int mini = min(x, y);
		int maxi = max(x, y);
		int d = maxi - mini + 1;
		int l = foo[d];
		sum += max(arr[l][mini], arr[l][maxi + 1 - bar[l]]);
		x += 7;
		while (x >= n - 1)
			x -= n - 1;
		y += 11;
		while (y >= n)
			y -= n;
	}
	cout << sum << endl;
	return 0;
}
