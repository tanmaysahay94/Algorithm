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
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		long long root(0), id, sum;
		while (n--)
		{
			cin >> id >> sum;
			root += id - sum;
		}
		cout << root << endl;
	}
	return 0;
}
