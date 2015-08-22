#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		long long a, b, ans = 0;
		scanf("%lld%lld", &a, &b);
		while (a != b)
		{
			if (b > a)
				swap(b, a);
			a >>= 1;
			ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
