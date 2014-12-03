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
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL n, a, b;
	cin >> n >> a >> b;
	VLL v(n), u(n);
	vector<bool> visited(n, false);
	for (LL i = 0; i < n; i++)
	{
		cin >> v[i];
		u[i] = v[i];
	}
	bool swapped = false;
	if (a > b)
	{
		swap(a, b);
		swapped = true;
	}
	sortv(v);
	map<LL, LL> idx, ans;
	map<LL, LL>::iterator it;
	for (LL i = 0; i < n; i++)
		idx[v[i]] = i;
	bool possible = true;
	for (LL i = n - 1; i >= 0; i--)
	{
		if (visited[i])
			continue;
		if ((it = idx.find(a - v[i])) != idx.end() and not visited[it->s])
		{
			visited[it->s] = visited[i] = 1;
			ans[v[i]] = ans[a - v[i]] = 0;
		}
		else if ((it = idx.find(b - v[i])) != idx.end() and not visited[it->s])
		{
			visited[it->s] = visited[i] = 1;
			ans[v[i]] = ans[b - v[i]] = 1;
		}
		else
		{
			possible = false;
			break;
		}
	}
	if (not possible)
		printf("NO\n");
	else
	{
		printf("YES\n");
		for (LL i = 0; i < n; i++)
		{
			if (swapped)
				ans[u[i]] ^= 1;
			printf("%lld ", ans[u[i]]);
		}
		printf("\n");
	}
}
