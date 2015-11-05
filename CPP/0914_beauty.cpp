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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.rbegin(), v.rend());
	int border = -1;
	int curr = 0;
	for (int i = 0; i < k; i++)
	{
		set<int> S;
		for (int j = 0; j <= border; j++)
			S.insert(v[j]);
		S.insert(v[curr]);
		curr++;
		if (curr == n)
		{
			border++;
			curr = border + 1;
		}
		cout << S.size() << ' ';
		for (auto s: S)
			cout << s << ' ';
		cout << '\n';
	}
	return 0;
}
