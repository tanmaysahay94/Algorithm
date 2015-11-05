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
	string a, b;
	cin >> a >> b;
	int m[10] = {0};
	for (auto c: b)
		m[c - '0']++;
	for (int i = 0; a[i]; i++)
		for (int j = 9; j >= 0; j--)
			if (m[j] > 0)
				if (j > a[i] - '0')
					a[i] = j + '0', m[j]--;
	cout << a;
	return 0;
}
