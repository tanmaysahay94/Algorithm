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
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int m, s;
	cin >> m >> s;
	if (m == 1 and s >= 0 and s <= 9)
	{
		cout << s << " " << s << endl;
		return 0;
	}
	if (s < 1 or s > 9*m)
	{
		cout << "-1 -1\n";
		return 0;
	}
	string minnum = string(m, '0');
	string maxnum = minnum;
	minnum[0] = maxnum[0] = '1';
	int curr = s - 1;
	for (int i = m - 1; i >= 0; i--)
	{
		int add = min(9, curr);
		minnum[i] += add;
		curr -= add;
	}
	curr = s - 1;
	for (int i = 0; i < m; i++)
	{
		int add = min(curr, 9 - (maxnum[i] - '0'));
		maxnum[i] += add;
		curr -= add;
	}
	cout << minnum << " " << maxnum << endl;
	return 0;
}
