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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a > b)
		cout << "First\n";
	else
		cout << "Second\n";
	return 0;
}
