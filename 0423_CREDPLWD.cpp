#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

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
	int n, m, i, j;
	cin >> n >> m;
	vector<vector<LL> > matrix(n, vector<LL> (m));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> matrix[i][j];

	return 0;
}
