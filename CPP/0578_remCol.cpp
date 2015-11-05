#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int n, m;
	cin >> n >> m;
	string v[1111];
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int cnt = 0;
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n - 1; i++)
			if (v[i] > v[i+1] and v[i][j] > v[i+1][j])
			{
				cnt++;
				for (int k = 0; k < n; k++)
					v[k][j] = 'z';
			}
	cout << cnt << endl;
	return 0;
}
