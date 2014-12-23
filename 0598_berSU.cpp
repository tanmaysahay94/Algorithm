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
	int n, m;
	cin >> n;
	VI a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	VI b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sortv(a); sortv(b);
	VI ub(n, 0), ug(m, 0);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		bool set = false;
		for (int j = 0; j < m and not set; j++)
		{
			if (abs(a[i] - b[j]) <= 1 and !ub[i] and !ug[j])
			{
				ub[i] = ug[j] = 1;
				count++;
				set = true;
			}
		}
	}
	cout << count << endl;
	return 0;
}
