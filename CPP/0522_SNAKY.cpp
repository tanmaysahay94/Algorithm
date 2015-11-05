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

const LL maxsize = 1111;

LL g[maxsize][maxsize], dx[256], dy[256];
char str[maxsize*maxsize+1];

void move(LL& x, LL& y, char c)
{
	x += dx[c];
	y += dy[c];
}

int main()
{
	dx['U'] = dx['D'] = dy['L'] = dy['R'] = 0;
	dx['R'] = dy['U'] = 1;
	dx['L'] = dy['D'] = -1;
	LL t, sim = 0;
	SLL(t);
	while (t--)
	{
		LL n, m, x, y, l;
		SLL(n); SLL(m); SLL(x); SLL(y); SLL(l);
		scanf("%s", str);
		g[x][y] = ++sim;
		for (LL i = 0; str[i]; i++)
		{
			move(x, y, str[i]);
			g[x][y] = ++sim;
		}
		LL start = sim;
		while (true)
		{
			move(x, y, str[l - 2]);
			if (x < 1 or x > n or y < 1 or y > m)
			{
				printf("WALL %lld\n", sim - start);
				break;
			}
			if (g[x][y] + l > sim + 1)
			{
				printf("BODY %lld\n", sim - start);
				break;
			}
			++sim;
		}
	}
	return 0;
}
