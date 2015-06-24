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
	LL k = 3;
	while (n % k == 0)
		k *= 3;
	cout << n / k + 1;
	return 0;
}
