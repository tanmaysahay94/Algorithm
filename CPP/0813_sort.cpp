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
	bool possible = true;
	int n;
	cin >> n;
	vector<int> v(n), w(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	w = v;
	sort(w.begin(), w.end());
	if (v == w) {cout << "yes\n1 1\n"; return 0;}
	int s = 0, e = n - 1;
	if (v[0] == w[0]) while (v[s] == w[s]) s++;
	if (v[n-1] == w[n-1]) while (v[e] == w[e]) e--;
	int left(s), right(e);
	int fixl(left), fixr(right);
	for (; possible and left <= fixr and right >= fixl; left++, right--)
		if (v[left] != w[right])
			possible = false;
	if (possible)
		cout << "yes\n" << fixl + 1 << ' ' << fixr + 1 << endl;
	else
		cout << "no\n";
	return 0;
}
