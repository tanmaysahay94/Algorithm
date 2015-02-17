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
	long long a, b, s;
	cin >> a >> b >> s;
	a = abs(a);
	b = abs(b);
	long long least = a + b;
	if ((s - least) % 2 == 0 and least <= s)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
