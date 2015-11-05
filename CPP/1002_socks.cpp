#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int v1 = min(a, b);
	a -= v1;
	b -= v1;
	int v2 = a / 2 + b / 2;
	cout << v1 << ' ' << v2;
	return 0;
}
