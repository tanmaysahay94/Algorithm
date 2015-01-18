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

const LL mod = 1e9 + 7;

vector<VI> nostress(2005, VI (2005, 0));
vector<VI> stress = nostress;
void preprocess()
{
	for (int i = 0; i < 2005; i++)
		stress[i][0] = nostress[i][0] = 1;
	for (int i = 1; i < 2005; i++)
		for (int j = i + 1; j < 2005; j++)
			nostress[j][i] = (nostress[j][i-1] + nostress[j-1][i]) % mod;
	for (int i = 1; i < 2005; i++)
		for (int j = i; j < 2005; j++)
			stress[j][i] = (stress[j][i-1] + stress[j-1][i]) % mod;
}

int main()
{
	preprocess();
	int t;
	si(t);
	for (int test = 1; test <= t; test++)
	{
		int a, b;
		scanf("%d-%d", &a, &b);
		printf("Case #%d: %d %d\n", test, nostress[a][b], stress[b][b]);
	}
	return 0;
}
