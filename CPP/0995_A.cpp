#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(8);
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		v[val]++;
	}
	if (v[7] or v[5] or (v[1] != v[2] + v[3]) or (v[2] + v[3] != v[4] + v[6]) or (v[2] < v[4]) or (v[6] < v[3]))
	{
		printf("-1\n");
		return 0;
	}
	v[2] -= v[4];
	while (v[4]--)
		printf("1 2 4\n");
	while (v[2]--)
		printf("1 2 6\n");
	while (v[3]--)
		printf("1 3 6\n");
	return 0;
}
