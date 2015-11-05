#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

long long solve()
{
	long long n, k, ans(0), foo(0), bread, buz;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> bread;
		if (foo >= bread)
			foo = foo - bread;
		else
		{
			bread = bread - foo;
			buz = (bread - 1) / k + 1;
			ans += buz;
			foo = buz * k - bread;
		}
		if (foo != 0)
			--foo;
	}
	return ans;
}

int main()
{
	optimizeIO();
	long long t;
	cin >> t;
	for (int T = 0; T < (int) t; T++)
		cout << solve() << '\n';
	return 0;
}
