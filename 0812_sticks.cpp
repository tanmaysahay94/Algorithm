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
	int n, m;
	cin >> n >> m;
	n = min(n, m);
	if (n & 1) cout << "Akshat\n";
	else cout << "Malvika\n";
	return 0;
}
