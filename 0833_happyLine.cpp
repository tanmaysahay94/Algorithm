#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

int main()
{
	optimizeIO();
	LL n;
	cin >> n;
	vector<LL> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
		v[i] += i;				// as at most i people can cross (i+1)th person
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		v[i] -= i;				// as (i+1)th guy has crossed i people
	bool yes = true;
	for (int i = 1; i < n and yes; i++)
		if (v[i] < v[i - 1])
			yes = false;
	if (not yes)
	{
		cout << ":(\n";
		return 0;
	}
	for (int i = 0; i < n; i++)
		cout << v[i] << ' ';
	cout << endl;
	return 0;
}
