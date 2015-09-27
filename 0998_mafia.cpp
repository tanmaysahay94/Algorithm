#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	LL n;
	scanf("%lld", &n);
	LL sum = 0;
	LL mx = -1;
	for (int i = 0; i < n; i++)
	{
		LL val;
		scanf("%lld", &val);
		mx = max(val, mx);
		sum += val;
	}
	if (sum % (n - 1) == 0)
		sum /= n - 1;
	else
		sum = sum / (n - 1) + 1;
	printf("%lld\n", max(sum, mx));
	return 0;
}
