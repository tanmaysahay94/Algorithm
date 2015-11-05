#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int mx = INT_MIN;
	vector<int> u(n);
	for (int i = n - 1; i >= 0; i--)
	{
		mx = max(mx, v[i]);
		if (v[i] != mx)
			u[i] = mx - v[i] + 1;
		else
			u[i] = 0;
	}
	for (auto uu: u)
		cout << uu << ' ';
	return 0;
}
