#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef unsigned long long ULL;

string louise = "Louise";
string richard = "Richard";

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		ULL N;
		cin >> N;
		ULL largest = 1;
		while ((largest << 1) < N) largest <<= 1;
		int player = 0;
		while (N != 1)
		{
			if (N & (N - 1))
				N -= largest;
			else
				N >>= 1;
			largest >>= 1;
			player ^= 1;
		}
		if (player == 0)
			cout << richard << '\n';
		else
			cout << louise << '\n';
	}
	return 0;
}
