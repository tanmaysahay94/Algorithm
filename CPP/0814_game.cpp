#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

bool f(LL n, LL k, LL d1, LL d2)
{
	if (n % 3) return false;
	for (int sg1 = -1; sg1 <= 1; sg1 += 2)
		for (int sg2 = -1; sg2 <= 1; sg2 += 2)
		{
			LL dd1 = d1 * sg1;
			LL dd2 = d2 * sg2;
			LL foo = (k - dd1 + dd2) / 3;
			if ((k - dd1 + dd2) % 3) continue;
			if (foo >= 0 and foo <= k)
			{
				LL bar = dd1 + foo;
				LL buz = foo - dd2;
				if (bar >= 0 and bar <= k and buz >= 0 and buz <= k)
					if (bar <= n/3 and foo <= n/3 and buz <= n/3)
					{
						assert(abs(bar - foo) == d1);
						assert(abs(foo - buz) == d2);
						return true;
					}
			}
		}
	return false;
}

int main()
{
	optimizeIO();
	LL n, k, d1, d2, t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k >> d1 >> d2;
		if (f(n, k, d1, d2)) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
