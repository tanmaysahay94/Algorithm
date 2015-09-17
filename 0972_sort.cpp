#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n), u(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		u[i] = v[i];
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (v[i] != u[i])
			cnt++;
	if (cnt <= 2)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
