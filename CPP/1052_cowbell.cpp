#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	LL n, k;
	scanf("%lld%lld", &n, &k);
	vector<LL> S(n);
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &S[i]);
		ans = max(ans, S[i]);
	}
	for (int i = 0; i < n - k; i++)
		ans = max(ans, S[i] + S[2 * (n - k) - i - 1]);
	printf("%lld\n", ans);
	return 0;
}
