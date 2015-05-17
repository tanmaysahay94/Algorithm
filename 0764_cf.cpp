#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void yes() {cout << "YES\n"; exit(0);}
void no() {cout << "NO\n"; exit(0);}
int main()
{
	optimizeIO();
	string s;
	cin >> s;
	string t("CODEFORCES");
	int idx = 0;
	bool p = true;
	for (int i = 0; i < (int) s.length() and p and idx < (int) t.length(); i++)
		if (s[i] == t[idx])
			idx++;
		else
			p = false;
	if (idx == (int) t.length())
		yes();
	int ind = t.length() - 1;
	p = true;
	for (int i = s.length() - 1; i >= 0 and p and ind >= 0; i--)
		if (s[i] == t[ind])
			ind--;
		else
			p = false;
	if (ind == -1 or ind <= idx - 1)
		yes();
	no();
	return 0;
}
