#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

vector<int> pre(maxn);

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &pre[i]);
		pre[i] += pre[i - 1];
	}
	int cnt = 0;
	for (int i = 1; i < n; i++)
		if (pre[i] == pre[n] - pre[i])
			cnt++;
	printf("%d\n", cnt);
	return 0;
}
