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
	string s, t, a;
	cin >> s >> t;
	int n = s.length();
	int cnt = 0;
	vector<int> l;
	a = s;
	for (int i = 0; i < n; i++)
		if (s[i] != t[i])
			cnt++, l.push_back(i);
	if (cnt & 1)
	{
		cout << "impossible\n";
		return 0;
	}
	for (int i = 0; i < cnt/2; i++)
		a[l[i]] = t[l[i]];
	cout << a << endl;
	return 0;
}
