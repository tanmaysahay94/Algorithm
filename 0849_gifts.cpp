#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

LL b, s, g;
vector<vector<LL> > mp(3);

int main()
{
	scanf("%lld%lld%lld", &b, &s, &g);
	vector<LL> tmp(b);
	for (int i = 0; i < b; i++)
		scanf("%lld", &tmp[i]);
	mp[0] = tmp;
	tmp.resize(s);
	for (int i = 0; i < s; i++)
		scanf("%lld", &tmp[i]);
	mp[1] = tmp;
	tmp.resize(g);
	for (int i = 0; i < g; i++)
		scanf("%lld", &tmp[i]);
	mp[2] = tmp;
	LL ptr[3][2];
	for (int i = 0; i < 3; i++)
		ptr[i][0] = 0;
	ptr[0][1] = b - 1;
	ptr[1][1] = s - 1;
	ptr[2][1] = g - 1;
	int ans = 0;
	for (int ii = 0; ii < b + s + g; ii++)
	{
		LL val;
		scanf("%lld", &val);
		LL foo[3][2];
		for (int i = 0; i < 3; i++)for (int j = 0; j < 2; j++) foo[i][j] = -1;
		int maxval = -1, whichone, frontOrBack;;
		for (int i = 0; i < 3; i++)
		{
			if (ptr[i][1] < ptr[i][0])
				continue;
			for (int j = 0; j < 2; j++)
			{
				foo[i][j] = val * mp[i][ptr[i][j]];
				if (foo[i][j] > maxval)
				{
					maxval = foo[i][j];
					whichone = i;
					frontOrBack = j;
				}
			}
		}
		ans += maxval;
		if (frontOrBack == 0)
			ptr[whichone][0]++;
		else
			ptr[whichone][1]--;
	}
	printf("%d\n", ans);
	return 0;
}
