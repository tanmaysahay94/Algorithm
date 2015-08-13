#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const int maxn = 1e6 + 5;

int P[maxn];

int main()
{
	optimizeIO();
	memset(P, 0, sizeof(P));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		P[val] = 1;
	}
	return 0;
}
