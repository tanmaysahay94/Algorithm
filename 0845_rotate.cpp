#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	for (int i = 0; i < q; i++)
	{
		int idx;
		scanf("%d", &idx);
		idx = (idx - k) % n;
		if (idx < 0) idx += n;
		printf("%d\n", v[idx]);
	}
	return 0;
}
