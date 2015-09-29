#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	long long sum = 0;
	int sz = 0, ans = 0, l = 0;
	for (int i = 0; i < n; i++)
	{
		sum += v[i];
		while (1LL * (i - l + 1) * v[i] > k + sum)
			sum -= v[l++];
		if (i - l + 1 > sz)
			ans = v[i], sz = i - l + 1;
	}
	printf("%d %d\n", sz, ans);
	return 0;
}
