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

#define INF 1000000000
// U R D L
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int getdir(char c)
{
	if(c == 'U')
		return 0;
	if(c == 'R')
		return 1;
	if(c == 'D')
		return 2;
	return 3;
}

int collission(int ax, int ay, int ad, int bx, int by, int bd)
{
	int x = ax-bx, y = ay-by;
	int ddx = dx[ad]-dx[bd];
	int ddy = dy[ad]-dy[bd];
	x*=2;
	y*=2;
	int v1 = 0, v2 = 0;
	if(ddx!=0 && x==0)
		return -1;
	if(ddy!=0 && y==0)
		return -1;
	if(ddx)
		v1=x/(-ddx);
	else if(x!=0)
		return -1;
	if(ddy)
		v2=y/(-ddy);
	else if(y!=0)
		return -1;
	if(v1==0 && v2==0 && (x>0 || y>0))
		return -1;
	if(v1==0 || v2==0 || (v1==v2))
		return v1|v2;
	else
		return -1;
}

int main()
{
	int t, n, x, y, d, ex, ey, ed, collt;
	scanf("%d",&t);
	char dir;
	while(t--)
	{
		scanf("%d%d %c", &ex, &ey, &dir);
		ed = getdir(dir);
		scanf("%d", &n);
		collt = -1;
		while(n--)
		{
			scanf("%d%d %c", &x, &y, &dir);
			d = getdir(dir);
			int dt = collission(ex, ey, ed, x, y, d);
			if(dt > 0)
			{
				if(collt < 0 || dt < collt)
					collt = dt;
			}
		}
		if(collt > 0)
			printf("%d.%d\n", collt/2, 5*(collt%2));
		else
			printf("SAFE\n");
	}
	return 0;
}
