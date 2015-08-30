#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		while (v[i] % 2 == 0) v[i] /= 2;
		while (v[i] % 3 == 0) v[i] /= 3;
	}
	sort(v.begin(), v.end());
	if (v[0] == v[n - 1]) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
