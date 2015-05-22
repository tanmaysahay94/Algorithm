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
	long long k, n, w;
	cin >> k >> n >> w;
	long long cost = k * (w * (w + 1)) / 2;
	if (cost > n) cout << cost - n << endl;
	else cout << 0 << endl;
	return 0;
}
