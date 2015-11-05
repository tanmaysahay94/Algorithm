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
	string a, b;
	cin >> a >> b;
	int dist = 0;
	for (int i = 0; i < (int) a.length(); i++)
		if (a[i] == '+')
			dist++;
		else
			dist--;
	int curr = 0, qMark = 0;
	for (int i = 0; i < (int) b.length(); i++)
		if (b[i] == '+')
			curr++;
		else if (b[i] == '-')
			curr--;
		else
			qMark++;
	int lim = 1 << qMark;
	int count = 0;
	for (int i = 0; i < lim; i++)
	{
		int delta = 0, j = i;
		for (int dig = 0; dig < qMark; dig++)
		{
			if (j & 1)
				delta++;
			else
				delta--;
			j >>= 1;
		}
		if (curr + delta == dist)
			count++;
	}
	printf("%.9lf\n", ((double)count)/((double)lim));
	return 0;
}
