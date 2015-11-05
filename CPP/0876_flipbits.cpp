#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef unsigned int u32;

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		u32 N;
		cin >> N;
		cout << ~N << '\n';
	}
	return 0;
}
