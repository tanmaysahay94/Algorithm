#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL n;
	SLL(n);
	vector<vector<LL> > mat(n, vector<LL> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			SLL(mat[i][j]);
	LL ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans += mat[i][j] * mat[j][i];
	ans = ans % 2;
	LL q, type, idx;
	SLL(q);
	while (q--)
	{
		SLL(type);
		if (type == 3)
			printf("%lld", ans);
		if (type == 1 or type == 2)
		{
			SLL(idx);
			ans = !ans;
		}
	}
	cout << endl;
	return 0;
}
