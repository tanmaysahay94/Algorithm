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
	int n;
	cin >> n;
	vector<long long> v(n);
	vector<long long> pre(n+1);
	int ans = 1;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	long long tm = v[0];
	for (int i = 1; i < n; i++)
		if (tm <= v[i])
			ans++, tm += v[i];
	cout << ans << endl;
	return 0;
}
