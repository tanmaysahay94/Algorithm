#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	LL l, r;
	cin >> l >> r;
	int i = 63;
	while (i >= 0 and (l & (1LL << i)) == (r & (1LL << i))) i--;
	i++;
	cout << (1LL << i) - 1LL;
	return 0;
}
