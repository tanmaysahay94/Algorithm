#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	if (n == k)
	{
		cout << -1;
		return 0;
	}
	vector<int> v(n+1);
	long long sum = (n * (n + 1)) / 2;
	for (int i = 2; i < k + 2; i++)
		v[i] = i, sum -= i;
	for (int i = k + 2; i <= n; i++)
		v[i] = i % n + 1, sum -= (i % n + 1);
	v[1] = sum;
	for (int a = 1; a <= n; a++)
		cout << v[a] << ' ';
	return 0;
}
