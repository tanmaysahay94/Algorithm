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
	LL base, minus, mul;
	cin >> n;
	if (n < 10) base = n, minus = n, mul = 1;
	else if (n < 100) base = 9, minus = 9, mul = 2;
	else if (n < 1000) base = 189, minus = 99, mul = 3;
	else if (n < 10000) base = 2889, minus = 999, mul = 4;
	else if (n < 100000) base = 38889, minus = 9999, mul = 5;
	else if (n < 1000000) base = 488889, minus = 99999, mul = 6;
	else if (n < 10000000) base = 5888889, minus = 999999, mul = 7;
	else if (n < 100000000) base = 68888889, minus = 9999999, mul = 8;
	else if (n < 1000000000) base = 788888889, minus = 99999999, mul = 9;
	else base = 8888888899, minus = n, mul = 0;
	cout << base + (n - minus) * mul;
	return 0;
}
