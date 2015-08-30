#include <bits/stdc++.h>

using namespace std;

int f(vector<int>& v)
{
	int idx = 0;
	for (int i = 1; i < (int) v.size(); i++)
		if (v[i] >= v[idx])
			idx = i;
	return idx;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int idx = f(v), ans = 0;
	while (idx)
	{
		v[0]++;
		v[idx]--;
		idx = f(v);
		ans++;
	}
	cout << ans;
	return 0;
}
