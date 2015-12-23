#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 1e5 + 5;

LL A[maxn], B[maxn];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lld", &A[i]);
		for (int i = 0; i < n; i++)
			scanf("%lld", &B[i]);
		bool pa = true, pb = true;
		for (int i = 1; i < n; i++)
		{
			bool npa(false), npb(false);
			if (pa)
			{
				if (A[i] >= A[i - 1]) npa |= true;
				if (B[i] >= A[i - 1]) npb |= true;
			}
			if (pb)
			{
				if (A[i] >= B[i - 1]) npa |= true;
				if (B[i] >= B[i - 1]) npb |= true;
			}
			pa = npa, pb = npb;
		}
		if (pa or pb) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
