#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

char p[1111111];

int main()
{
	map<char, int> mp;
	mp['c'] = 0;
	mp['h'] = 1;
	mp['e'] = 2;
	mp['f'] = 3;
	long long q, l, r;
	char a, b;
	scanf("%s", p);
	const int len = strlen(p);
	vector<vector<long long> > pre(4, vector<long long> (len + 1));
	vector<vector<vector<long long> > > ans(4, vector<vector<long long> > (4, vector<long long> (len + 1)));
	for (int i = 0; i < len; i++)
	{
		pre[0][i + 1] = pre[0][i] + (p[i] == 'c');
		pre[1][i + 1] = pre[1][i] + (p[i] == 'h');
		pre[2][i + 1] = pre[2][i] + (p[i] == 'e');
		pre[3][i + 1] = pre[3][i] + (p[i] == 'f');
	}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 1; k <= len; k++)
			{
				ans[i][j][k] = ans[i][j][k - 1];
				if (pre[j][k] - pre[j][k - 1] == 1)
					ans[i][j][k] += pre[i][k];
			}
	scanf("%lld", &q);
	while (q--)
	{
		getchar();
		scanf("%c %c %lld%lld", &a, &b, &l, &r);
		int start_char = mp[a];
		int end_char = mp[b];
		printf("%lld\n", ans[start_char][end_char][r] - ans[start_char][end_char][l - 1] - pre[start_char][l - 1] * (pre[end_char][r] - pre[end_char][l - 1]));
	}
	return 0;
}
