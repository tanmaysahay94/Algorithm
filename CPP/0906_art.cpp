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
	vector<int> a(2), b(2), c(2);
	for (int i = 0; i < 2; i++) cin >> a[i];
	for (int i = 0; i < 2; i++) cin >> b[i];
	for (int i = 0; i < 2; i++) cin >> c[i];
	bool ok = false;
	for (int i = 0; i < 2 and not ok; i++)
		for (int j = 0; j < 2 and not ok; j++)
			for (int k = 0; k < 2 and not ok; k++)
				if ((a[i] >= b[j] + c[k] and a[i^1] >= max(b[j^1], c[k^1])) or (a[i^1] >= b[j] + c[k] and a[i] >= max(b[j^1], c[k^1])))
					ok = true;
	if (ok)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
