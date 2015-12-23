#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<int> pre(n), suf(n);
	pre[0] = v[0];
	suf[n - 1] = v[n - 1];
	for (int i = 1, j = n - 2; i < n and j >= 0; i++, j--)
		pre[i] = max(pre[i - 1], v[i]), suf[j] = min(suf[j + 1], v[j]);
	int cnt = 1;
	for (int i = 0; i + 1 < n; i++)
		if (pre[i] <= suf[i + 1])
			cnt++;
	cout << cnt;
	return 0;
}
