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
	LL t, n;
	SLL(t);
	while (t--)
	{
		SLL(n);
		vector<string> grid(n);
		vector<LL> rowLast(n, -1), colLast(n, -1);
		for (int i = 0; i < n; i++)
			cin >> grid[i];
		for (int i = 0; i < n; i++)
			for (int j = n - 1; j >= 0; j--)
			{
				if (grid[i][j] == '#')
				{
					rowLast[i] = j;
					break;
				}
			}
		for (int i = 0; i < n; i++)
			for (int j = n - 1; j >= 0; j--)
			{
				if (grid[j][i] == '#')
				{
					colLast[i] = j;
					break;
				}
			}
/*		for (int i = 0; i < n; i++)
			cout << rowLast[i] << " ";
		cout << endl;
		for (int i = 0; i < n; i++)
			cout << colLast[i] << " ";
		cout << endl;*/
		LL ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (i > colLast[j] and j > rowLast[i])
					ans++;
			}
		cout << ans << endl;
	}
	return 0;
}
