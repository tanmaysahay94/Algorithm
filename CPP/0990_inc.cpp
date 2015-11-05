#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	int curr = 1;
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		if (v[i] >= v[i - 1])
			curr++;
		else
		{
			ans = max(ans, curr);
			curr = 1;
		}
	}
	ans = max(ans, curr);
	printf("%d\n", ans);
	return 0;
}
