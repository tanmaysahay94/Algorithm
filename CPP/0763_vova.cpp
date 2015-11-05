#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void sigh()
{
	cout << -1 << endl;
	exit(0);
}

int main()
{
	optimizeIO();
	int n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;
	int a[1001];
	for (int i = 0; i < k; i++)
		cin >> a[i];
	int cnt = 0;
	for (int i = 0; i < k; i++)
		if (a[i] < y)
			cnt++;
	if (cnt > n/2) sigh();
	cnt = n/2 - cnt;
	for (int i = 0; i < n - k; i++)
		if (i < cnt)
			a[k + i] = 1;
		else
			a[k + i] = y;
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	if (sum > x) sigh();
	for (int i = k; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}
