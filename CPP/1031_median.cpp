#include <bits/stdc++.h>

using namespace std;

vector<int> f(vector<int> &v)
{
	vector<int> u(v);
	vector<int> cnt(2);
	for (int i = 1; i + 1 < (int) v.size(); i++)
	{
		for (int j = i - 1; j <= i + 1; j++)
			cnt[v[j]]++;
		u[i] = cnt[0] > cnt[1] ? 0 : 1;
		for (int j = 0; j < 3; j++)
			cnt[j] = 0;
	}
	return u;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n), u(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	u = f(v);
	if (u == v)
	{
		cout << 0 << endl;
		for (auto V: v)
			cout << V << ' ';
		return 0;
	}
	int cnt = 0;
	while (u != v)
	{
		v = u;
		u = f(u);
		cnt++;
	}
	cout << cnt << endl;
	for (auto V: v)
		cout << V << ' ';
	return 0;
}
