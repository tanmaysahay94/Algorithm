#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int val;
		scanf("%d", &val);
		int idx = lower_bound(v.begin(), v.end(), val) - v.begin();
		printf("%d\n", idx);
	}
	return 0;
}
