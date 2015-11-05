#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int n;
	scanf("%d", &n);
	vector<pair<LL, LL> > v(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &v[i].first);
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end());
	if (n % 2 == 0)
	{
		printf("%d\n", n / 2);
		for (int i = 0; i < n; i += 2)
			printf("%lld ", v[i].second);
		printf("\n");
		printf("%d\n", n / 2);
		for (int i = 1; i < n; i += 2)
			printf("%lld ", v[i].second);
	}
	else
	{
		printf("%d\n", n / 2 + 1);
		printf("%lld ", v[n - 2].second);
		for (int i = n - 3; i >= 0; i -= 2)
			printf("%lld ", v[i].second);
		printf("\n");
		printf("%d\n", n / 2);
		printf("%lld ", v[n - 1].second);
		for (int i = n - 4; i >= 0; i -= 2)
			printf("%lld ", v[i].second);
	}
	return 0;
}
