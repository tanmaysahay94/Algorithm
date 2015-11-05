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
	LL a1, a2, a3, a4, a5, a6;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	cout << (a1 + a2 + a3) * (a1 + a2 + a3) - a1 * a1 - a3 * a3 - a5 * a5;
	return 0;
}
