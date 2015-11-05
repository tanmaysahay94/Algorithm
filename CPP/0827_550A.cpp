#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void show(vector<bool>& v)
{
	for (int i = 0; i < (int) v.size(); i++)
		cout << v[i];
	cout << endl;
}
int main()
{
	optimizeIO();
	string s;
	cin >> s;
	int n = s.length();
	vector<bool> preab(n, false), postab(n, false), preba(n, false), postba(n, false);
	for (int i = 1; i < n; i++)
	{
		preab[i] = preab[i - 1];
		preba[i] = preba[i - 1];
		char c = s[i -1];
		char d = s[i];
		if (c == 'A' and d == 'B') preab[i] = true;
		if (c == 'B' and d == 'A') preba[i] = true;
	}
	for (int i = n - 2; i >= 0; i--)
	{
		postab[i] = postab[i + 1];
		postba[i] = postba[i + 1];
		if (postab[i] and postba[i]) continue;
		char c = s[i];
		char d = s[i + 1];
		if (c == 'A' and d == 'B') postab[i] = true;
		if (c == 'B' and d == 'A') postba[i] = true;
	}
//	show(preab); show(preba); show(postab); show(postba);
	bool yes = false;
	for (int i = 1; i + 1 < n and not yes; i++)
		if ((preab[i] and postba[i + 1]) or (preba[i] and postab[i + 1]))
			yes = true;
	if (yes) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
