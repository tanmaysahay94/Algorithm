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
	int t;
	VI v(3);
	vector<string> str(4);
	VI team(4);
	vector<string> teamName;
	si(t);
	while (t--)
	{
		for (int i = 0; i < 3; i++)
			si(v[i]);
		for (int i = 0; i < 4; i++)
		{
			cin >> str[i];
			if (str[i][0] == 'E' or str[i][0] == 'N')
				team[i] = 0;
			else
				team[i] = 1;
		}
	}
	return 0;
}
